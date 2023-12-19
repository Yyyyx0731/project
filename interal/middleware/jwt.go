package middleware

import (
	"github.com/dgrijalva/jwt-go"
	"github.com/gin-gonic/gin"
	"github.com/travel_study/blog-service/pkg/app"
	"github.com/travel_study/blog-service/pkg/errcode"
)


func JWT() gin.HandlerFunc {
	return func(c *gin.Context) {
		var (
			token string
			ecode = errcode.Success
		)
		if s, exist := c.GetQuery("token"); exist { //如果存在
			token = s
		} else { //不存在
			token = c.GetHeader("token") //从 Header 中获取 token 参数
		}
		if token == "" { //如果token是空
			ecode = errcode.InvalidParams
		} else { //token不为空
			_, err := app.ParseToken(token)  //对token进行解析
			if err != nil {
				switch err.(*jwt.ValidationError).Errors {
					case jwt.ValidationErrorExpired: //过期
						ecode = errcode.UnauthorizedTokenTimeout
					default:
						ecode = errcode.UnauthorizedTokenError
				}
			}
		}

		if ecode != errcode.Success { //没成功
			response := app.NewResponse(c)
			response.ToErrorResponse(ecode) //响应返回错误
			c.Abort() //终止后续中间件的执行
			return
		}

		c.Next() //继续执行后续中间件
	}
}





