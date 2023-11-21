package timer

import "time"

func GetNowTime() time.Time{
	//设置当前时区为Asia/Shanghai
	location,_ := time.LoadLocation("Asia/Shanghai")
	return time.Now().In(location)
}

func GetCalculateTime(currentTimer time.Time,d string)(time.Time,error){
	duration,err := time.ParseDuration(d)//从字符串中解析出duration（持续时间）
	if err != nil {
		return time.Time{},err
	}
	return currentTimer.Add(duration),nil //add得到时间加上duration后得到的最终时间
}
