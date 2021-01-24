# CurrencyRateConvertor-汇率计算器
## 原理
1. 从json文件读取货币信息，利用正则从网站爬取汇率
2. 完成计算
## 使用说明
下载地址https://github.com/mojovs/CurrencyRateConvertor/releases/download/0.1/Convertor-0.1.7z

使用的时候要在程序同级目录，放一个名为  "货币列表.json"的文件(以后有时间改成直接界面添加)，
__货币列表.json已经随源码附带__
#### 添加更多货币
json列表的格式如下代码，想要添加其他货币，只需要改动的点为：
1. "currencyName"：[],在[]里面添加想用的货币名称（可以自己命名）。
2. "currencySymbol":{},在{}里面添加键值对。
	 键为之前在currencyName里面写入的货币名称;
	 值为通用国际货币简写符号。
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
