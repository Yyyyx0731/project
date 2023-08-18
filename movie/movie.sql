

create table users(
    id int not null auto_increment primary key ,
    username varchar(100) not null ,
    password varchar(100) not null ,
    tel varchar(100) not null
);






DROP TABLE IF EXISTS `movies`;
create table movies(
    id int not null auto_increment primary key ,
    name varchar(100) not null unique ,
    director varchar(100) not null ,
    type varchar(100) not null ,
    time int not null ,
    online_time varchar(100) not null ,
    where_online varchar(100) not null ,
    version varchar(100) not null ,
    introduce varchar(1000) not null,
    img_path varchar(100) not null,
    amount double(11,2) not null ,
    score double(3,1) not null
);

insert into movies values (1,'孤注一掷','申奥','神话 动作 史诗',130,'2023-08-08','中国大陆','国语2D','电影取材自上万起真实诈骗案例，境外网络诈骗全产业链骇人内幕将在大银幕上首度被揭秘。程序员潘生（张艺兴 饰）、模特安娜（金晨 饰）被海外高薪招聘吸引，出国淘金，却意外落入境外诈骗工厂的陷阱。为了离开，两人准备向赌徒阿天（王大陆 饰）和其女友小雨（周也 饰）下手，从他们身上套现、完成业绩……潘生与安娜能否逃过诈骗集团头目陆经理（王传君 饰）和阿才（孙阳 饰）的残暴折磨？面对警察（咏梅 饰）的跨国调查和追捕，他们又会何去何从?','static/img/孤注一掷.jpg',14.84,9.2);
insert into movies values (2,'热烈','大鹏','青春 励志',124,'2023-07-28','中国大陆','国语2D','街舞老炮儿丁雷，偶遇卖艺少年陈烁，丁雷忽悠陈烁加入自己经营的舞团。舞团内高手如云，性格各异，与陈烁碰撞出不同的火花，笑料不断。陈烁热烈追梦，期待着上场的机会，却发现丁雷邀请他其实另有目的，而丁雷和陈烁，也都将面对接二连三的沉重打击，他们能否逆风翻盘，回击人生难题？','static/img/热烈.jpg',8.03,9.4);
insert into movies values (3,'长安三万里','谢君伟','历史 动画',168,'2023-07-08','中国大陆','国语2D','安史之乱爆发后数年，吐蕃大军攻打西南。大唐节度使高适交战不利，长安岌岌可危。困守孤城的高适向监军太监回忆起自己与李白的一生往事。','static/img/长安三万里.jpg',16.99,9.4);
insert into movies values (4,'消失的她','崔睿','悬疑 犯罪 剧情',122,'2023-06-22','中国大陆','国语2D','金牌监制陈思诚继《误杀》系列后又一悬疑力作，朱一龙、倪妮、文咏珊、杜江俊男美女狂飙演技，剧情过山车反转停不下来！何非（朱一龙 饰）的妻子李木子（文咏珊 饰）在结婚周年旅行中离奇消失，在何非苦寻无果之时妻子再次现身，何非却坚持眼前的陌生女人并非妻子，妻子拿出了身份证明进行自证，夫妻二人似乎都有不可告人的秘密，随着金牌律师陈麦（倪妮 饰）介入到这起离奇案件中，更多的谜团慢慢浮现……究竟谁在说谎？端午佳节一起沉浸解谜。','static/img/消失的她.jpg',35.18,9.2);
insert into movies values (5,'芭比','格蕾塔·葛韦格','喜剧 冒险 奇幻',114,'2023-07-21','美国','原版2D','在芭比乐园里，各种各样的芭比和肯每天都过着童话般100%完美的生活。但是某一天，芭比发现自己的生活开始有了变化——比如她的一天不再一帆风顺，她开始思考死亡的意义，甚至她的双脚也不再是完美的高跟鞋形——她竟然脚掌落地了！接连出现的不完美打破了芭比乐园的平静，意识到存在感危机的芭比被迫前往真实世界探寻真相，肯也一路同行，一场大冒险就此开启！','static/img/芭比.jpg',2.39,9.0);
insert into movies values (6,'封神第一部','乌尔善','神话 动作 史诗',148,'2023-07-20','中国大陆','国语2D','','static/img/封神第一部.jpg',19.39,9.4);
insert into movies values (7,'巨齿鲨2：深渊','本·维特利','冒险 动作 科幻',119,'2023-08-04','中国大陆，美国','原版2D','海洋霸主巨齿鲨，今夏再掀狂澜！乔纳斯·泰勒（杰森·斯坦森 饰）与科学家张九溟（吴京 饰）双雄联手，进入海底7000米深渊执行探索任务。他们意外遭遇史前巨兽海洋霸主巨齿鲨群的攻击，还将对战凶猛危险的远古怪兽群。惊心动魄的深渊冒险，巨燃巨爽的深海大战一触即发……','static/img/.jpg',6.00,9.0);
insert into movies values (8,'最遗憾是错过你','詹馥华','剧情 爱情',115,'2023-08-22','中国台湾','国语2D','如果再想起青春里那个爱过、痛过的人，你还会有遗憾吗？当热情阳光的黄子捷（连晨翔 饰）遇见单纯善良的张筱华（吴子霏 饰），从一开始的互不打扰，到两个人慢慢互相了解、难掩心动，爱情的火花慢慢绽放，但命运的齿轮也仍在向前……世上最遗憾的不是不爱了，而是明明相爱却无能为力，错过一辆车可以等，但错过一个人，就是一辈子。','static/img/.jpg',0,0);
insert into movies values (9,'茶啊二中','夏铭泽','动画 奇幻 喜剧',91,'2023-07-14','中国大陆','国语2D','在“茶啊二中”，有最懂“我们”的中国式青春！当“学渣”王强与“暴力班主任”石妙娜意外灵魂互换，会是怎样“翻身解气”的体验？暑假解压包式强喜剧，7月14日，一起回到笑得最大声的日子！','static/img/茶啊二中.jpg',3.50,9.4);
insert into movies values (10,'超能一家人','宋阳','喜剧 家庭 奇幻',113,'2023-07-21','中国大陆','国语2D','君问归期已有期，超能定档721！暑期档的快乐来了！郑前（艾伦 饰）新开发的APP被狡猾又诚实的反派乞乞科夫（沈腾 饰）盯上了。幸好郑前一家人意外获得了超能力，姐姐会飞天，爸爸能隐身，爷爷不死术，妹妹力大无穷。郑前本指望家人们出手帮忙，一家人却常常出糗帮倒忙，虽强但傻的“超能力一家人”将如何对抗乞乞科夫，一场超能力VS钞能力的大战一触即发…… 本片改编自电影《超能力家庭Супербобровы》','static/img/超能一家人.jpg',3.00,8.0);
insert into movies values (11,'八角笼中','王宝强','剧情',117,'2023-07-06','中国大陆','国语2D','年度最受期待现实佳作！根据真实事件改编，王宝强诚意打造普通人改写命运之路！电影讲述了向腾辉（王宝强 饰）倾注心血想把当地无人照料的孩子培养成才，这让生活本没有出路的孩子们看到了一丝通向未来的曙光。然而，随着往日的表演视频被爆出，这些“残忍、血腥”的画面刺激了不明真相的人们的神经。一夜之间，舆论开始发酵。向腾辉的生活、孩子们的前途都陷入到人们以善良为名编织的大网中，让 他们难以挣脱，重回泥沼，关于未来，他们的“出路”又将在哪……','static/img/八角笼中.jpg',21.66,9.5);
insert into movies values (12,'我爱你！','韩延','剧情 爱情 家庭',117,'2023-06-21','中国大陆','国语2D','影帝影后绝赞演技，年度爱情片神作，带你领悟爱情真谛。你是否想过自己会如何老去？四个花甲老人，两段迟暮之恋，他们的爱善良而纯粹、浪漫又浓烈。在生命这段有限的旅程里，趁还来得及，我要对你说声\“我爱你！\”。','static/img/.我爱你！jpg',4.28,9.5);
insert into movies values (13,'我经过风暴','秦海燕','剧情 家庭',101,'2023-08-17','中国大陆','国语2D','','static/img/我经过风暴.jpg',0,0);
insert into movies values (14,'学爸','苏亮','剧情 喜剧',118,'2023-08-18','中国大陆','国语2D','黄渤强势回归现实主义题材，演绎小人物的命运与挣扎，展现中国万千家庭面貌，“卷不动又躺不平”的人生百态直击人心！ 雷大力（黄渤 饰）为了让儿子雷小米（单禹豪 饰）能够拥有更高的人生起点，在单亲妈妈刘真真（闫妮 饰）的带领下，被迫卷入了“幼升小”的激烈角逐。又在火哥（张子贤 饰）和火嫂（万茜 饰）的影响下，不惜倾尽所有购入学区房，重重压力让父子二人的生活变得不堪一击。雷小米小姨（张钧甯 饰）的出现，又让雷大力领悟了“拼娃”的本质是“拼父母”……面对残酷的现实，父子的生活困境应该如何破局？几组家庭又将做出怎样的人生抉择？','static/img/学爸.jpg',0,0);
insert into movies values (15,'变形金刚：超能勇士崛起','小斯蒂芬·卡普尔','动作 科幻 冒险',128,'2023-06-09','美国','原版2D','2023年顶级大银幕视觉盛宴来袭！时隔5年，变形金刚震撼归来！故事重返上世纪90年代，终极反派宇宙大帝从天而降，驱使以天灾为首的恐惧兽掀起地球危机。绝境之中，蛰伏许久的巨无霸终觉醒，联合汽车人变形出发！一场前所未有的史诗决战即将上演！','static/img/变形金刚：超能勇士崛起.jpg',6.54,9.0);
insert into movies values (16,'超级飞侠：乐迪加速','冯操','动画 冒险 喜剧 科幻',89,'2023-07-08','中国大陆','国语2D','超级飞侠乐迪接到一项新任务！一个神秘的包裹，一次跨越大洲的派送，乐迪却因此偶然介入了一场将世界陷于危机的恶作剧中。面对危机，乐迪和其他超级飞侠将发挥各自的救援能力，争分夺秒合力拯救世界！','static/img/超级飞侠：乐迪加速.jpg',0.68,8.7);
insert into movies values (17,'灌篮高手','井上雄彦','动画 青春 热血',124,'2023-04-20','日本','原版2D','影片讲述全民期待了27年的全国大赛。 宫城良田、三井寿、流川枫、樱木花道和赤木刚宪终于站在全国大赛的赛场，代表湘北高中与日本最强球队山王工业展开激烈对决。上半场两队势均力敌，下半场在山王盯人战术的高压之下，湘北节节落败。 面对强大的对手和几乎不可能追回的悬殊分差，湘北五人组能够再一次践行永不言弃的精神，突破自我团结一致，在这场生死大战中反败为胜吗？','static/img/灌篮高手.jpg',6.85,9.2);
insert into movies values (18,'燃冬','陈哲艺','剧情 爱情',97,'2023-08-22','中国大陆','国语2D','三个异乡人，一次冬天里的心跳邂逅。 娜娜（周冬雨饰）与韩萧（屈楚萧饰）暧昧僵持已久，没想到浩丰（刘昊然饰）的偶然闯入，令他们的关系悄然发生了变化。在心动、试探与矛盾间，三人深埋于心的秘密也逐渐显现…','static/img/燃冬.jpg',0,0);
insert into movies values (19,'碟中谍7：致命清算（上）','克里斯托夫·迈考利','动作 冒险 惊悚',164,'2023-07-14','美国','原版2D','刷新极限的传奇特工系列火线回归，感受今夏最真实震撼的银幕冒险！特工伊森·亨特（汤姆·克鲁斯饰）和他的IMF小组将开启迄今为止最危险的一次任务：追踪一种会危及全人类性命的新型武器，并阻止其落入坏人之手。与此同时，伊森曾对抗过的黑暗势力也正在卷土重来，整个世界的命运岌岌可危。面对神秘而强大的敌人，他不得不面对选择使命还是至爱的终极抉择。','static/img/碟中谍7：致命清算（上）.jpg',3.44,9.0);
insert into movies values (20,'棉花糖和云朵妈妈1宝贝芯计划','徐铮','喜剧 动画 冒险',88,'2023-07-01','中国大陆','国语2D','还记得大头儿子最好的朋友棉花糖吗？那个仗义、勇敢、包容、聪明的小姑娘？她的第一部大电影就要上映啦！孩子们暑假的第一部动画电影！无限想象、尽情释放！棉花糖首部大电影欢乐来袭！棉花糖一直有个大大的梦想，就是成为机器人科学家。一次机缘巧合，棉花糖和云朵妈妈真的获得了设计发明机器人的机会，但却又不得不面对重重的困难和挑战，以及迎接一次又一次的失败，她们最终能造出棉花糖想要的机器人吗？Q弹可爱的果冻机器人为何突然失控？母女二人又是如何鼓励对方、共同携手完成梦想的呢？温暖欢乐的故事，精彩有趣的历险，欢迎来到棉花糖的甜蜜夏天！','static/img/棉花糖和云朵妈妈1宝贝芯计划.jpg',0.13,9.0);
insert into movies values (21,'最后的真相','李太阁','剧情 悬疑 犯罪',125,'2023-08-25','中国大陆','国语2D','落魄律师丁义峰接到一桩看似证据确凿的“铁案”，他决心以“无罪辩护”东山再起。让人意想不到的是，嫌疑人金喜妹拒绝了丁义峰，竟一心求死。眼见是否必定为实？耳听是否必定为虚？重重迷雾之下，真相扑朔迷离……','static/img/最后的真相.jpg',0,0);





DROP TABLE IF EXISTS `cinema`;
create table cinema(
    id int not null auto_increment primary key ,
    name varchar(100) not null ,
    password varchar(100) not null,
    address varchar(100) not null
);

insert into cinema values (1,'MG影城','123456','芒果大厦7层');
insert into cinema values (2,'奇幻家影院','123456','光明村123号');
insert into cinema values (3,'北极昼影城','123456','桐木村138号');






create table room(
    id int not null auto_increment primary key ,
    name varchar(100) not null ,
    seat_row int not null ,
    seat_column int not null ,
    cinemaID int not null ,
    foreign key(cinemaID) references cinema(id)
);

insert into room values (1,'行星纪元',5,7,1);
insert into room values (2,'星晨',5,7,1);
insert into room values (3,'桃元',5,7,1);
insert into room values (4,'郭何拆桥',5,7,2);
insert into room values (5,'石郭拌饭',5,7,3);
insert into room values (6,'齐次方',5,7,3);
insert into room values (7,'恩格尔系树',5,7,2);
insert into room values (8,'弘叶题石',5,7,1);









DROP TABLE IF EXISTS `time`;
create table time(
    id int not null auto_increment primary key ,
    movie_ID int not null ,
    date varchar(100) not null ,
    time varchar(100) not null ,
    price double(10,2) not null ,
    roomID int not null ,
    foreign key(roomID) references room(id)
);

insert into time values (1,'1','2023-08-14','10:30',45,1);
insert into time values (2,'2','2023-08-14','12:30',41,3);
insert into time values (3,'1','2023-08-15','10:30',45,2);
insert into time values (4,'1','2023-08-15','15:30',45,2);
insert into time values (5,'2','2023-08-16','14:30',45,2);
insert into time values (6,'1','2023-08-16','17:30',45,1);





DROP TABLE IF EXISTS `orders`;
create table orders(
    id varchar(100) not null primary key ,
    date varchar(100) not null ,
    count int not null ,
    amount double(11,2) not null ,
    userID int not null ,
    foreign key(userID) references users(id)
);






DROP TABLE IF EXISTS `orderItems`;
create table orderItems(
    id int not null primary key auto_increment,
    orderID varchar(100) not null ,
    timeID int not null ,
    seat_row int not null ,
    seat_column int not null ,
    price double(11,2) not null ,
    foreign key(timeID) references time(id),
    foreign key(orderID) references orders(id)
);








DROP TABLE IF EXISTS `seats`;
create table seats(
    id int not null  primary key auto_increment,
    seat_row int not null ,
    seat_column int not null ,
    statues int not null ,  /* 0是可选（白），1是已售（红）*/
    roomID int not null ,
    foreign key (roomID) references room(id)
);
alter table seats add first int not null ;







CREATE TABLE `sessions1` (
   `session_id` varchar(100) NOT NULL,
    `cinemaName` varchar(100)  NOT NULL,
    `cinema_id` int NOT NULL,
    PRIMARY KEY (`session_id`) USING BTREE,
    KEY `user_id` (`cinema_id`) USING BTREE,
   FOREIGN KEY (`cinema_id`) REFERENCES `cinema` (`id`)
);