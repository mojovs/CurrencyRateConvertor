# CurrencyRateConvertor-汇率计算器
## 原理
1. 从json文件读取货币信息，利用正则从网站获取汇率
2. 完成计算
## 使用说明
使用的时候要在程序同级目录，放一个名为  "货币列表.json"的文件(以后有时间改成直接界面添加)，
json列表的格式如下:
```json
{
	"name":"在线货币",
	"url":"https://cn.exchange-rates.org/converter/CNY/",
	"currencyName":[
		"阿根廷比索",
		"俄罗斯卢布",
		"美国美元"
	],
	"currencySymbol":{
		"阿根廷比索":"ARS",
		"俄罗斯卢布":"RUB",
		"美国美元":"USD"

	}
}
```
