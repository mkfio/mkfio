去中心化交易所测试流程：
-------------------------------------------------------------------
# 实现原理：
## 一、挂单模板地址参数：
```
1）挂单地址：挂单者的地址，用于接收跨链交易的TOKEN；
2）币对：卖买双方的交易对，如：BBC/MKF，指BBC与MKF交易，完成跨链交易后，本挂单者的地址在MKF链上接收MKF的TOKEN；
3）价格：指本方的一个TOKEN兑换对方的多少TOKEN；
4）费率：指给撮合者和跨链交易者的奖励的费率，交易数量剩于费率即为奖励数量，由撮合者和跨链交易者平分，缺省费率为0.2%；
5）秘密hash：是挂单者随机生成原HASH，经过sha256计算得到的秘密hash；
6）原HASH加密数据表：原HASH是计算秘密HASH的原始数据，该参数的用途是将原HASH传递给跨链交易者，为了安全，需要加密存储在模板参数中，加密方法：使用跨链交易者的公钥加密，而跨链交易者使用自已的私钥解密，即可得到原HASH，存储顺序与跨链交易者地址表的存储顺序一至；
7）有效高度：在该高度以下，挂单者无法从该模板地址转出TOKEN，而撮合者可以完成撮合操作，即从该模板地址转到撮合模板地址；到达这个高度之后，挂单者可以从该地址转出所有TOKEN，并且撮合者将无法撮合，即无法从该模板地址转出TOKEN；
8）撮合或跨链处理的高度段：撮合或跨链交易可以有多个地址，各个地址按顺序完成撮合或交易，每个地址有一个完成工作的高度段，该参数配置一个地址完成工作的段高度；高度段计算从有效高度开始向下计算，最后一个地址的处理高度为：有效高度-高度段，至有效高度，前一个地址的处理高度依次向下计算；
9）撮合者地址表：挂单者指定的撮合者的地址表（或随机分配的），可以有多个撮合者，按高度段顺序撮合，第一高度段由第一个撮合者撮合，过了第一高度段还未撮合，则由第二个撮合者撮合，如此类推；撮合高度段缺省为1000个高度；
10）跨链交易者地址表：挂单者指定的跨链交易者的地址表，可以有多个跨链交易者，按高度段顺序处理跨链交易，缺省一个交易高度段为1000；
```

## 二、撮合模板地址参数：
```
1）撮合者地址：撮合者获取撮合奖励的地址，撮合交易的签名也是使用该地址对应的私钥签名；
2）交易数量：完成撮合的TOKEN数量，指本端卖出的TOKEN数量；
3）卖方费率：指给撮合者和跨链交易者的奖励的费率，交易数量剩于费率即为奖励数量，由撮合者和跨链交易者平分，缺省费率为0.2%，该参数需要与挂单模板中的费率相同；
4）卖方挂单模板地址：卖方挂单交易中的挂单模板地址，与卖方的挂单模板地址相同；
5）卖方挂单地址：卖方挂单者的地址，与卖方的挂单模板地址中的挂单地址相同；
6）卖方跨链交易者地址表：卖方挂单者指定的跨链交易者的地址表，与卖方的挂单模板地址中的跨链交易者地址表一至；
7）卖方的有效高度：同卖方的挂单模板地址中的有效高度一至；
8）卖方的高度段：同卖方的挂单模板地址中的有撮合或跨链处理的高度段一至；
9）买方挂单模板地址：买方挂单交易中的挂单模板地址；
10）买方挂单者地址：买方的挂单模板地址中的挂单者地址；
11）买方的秘密hash：买方的挂单模板地址中的秘密hash；
12）买方的有效高度：买方的挂单模板地址中的有效高度；
```

## 三、秘密HASH的生成和较验：
```
1）秘密HASH由挂单者生成；
2）挂单者随机生成一个HASH，该HASH为原HASH，挂单者使用sha256计算原HASH，得到秘密HASH；
3）挂单者选择跨链交易者，使用跨链交易者的公钥，加密原HASH，得到加密数据，该加密数据用于跨链交易者使用；
4）挂单者将秘密HASH和原HASH加密数据放在挂单模板地址参数中，用于后面的较验；
5）挂单表中的原HASH加密字段可能有多个原HASH加密数据，每一个加密HASH对应一个跨链交易者的加密，而加密顺序与跨链交易者字段中的跨链交易者的顺序一致，即一一对应跨链交易者的加密；
6）跨链交易者使用自已的私钥解密原HASH加密数据，得到挂单者生成的原HASH；
7）秘密HASH较验：将原HASH经过sha256计算得到的HASH，和秘密HASH比对来完成较验；
```

## 四、撮合逻辑：
```
1）撮合方收集两条链的挂单信息，两条链上的挂单同时满足同一个撮合方的撮合条件时，则由该撮合方完成撮合；
2）同时满足同一个撮合方的撮合条件：两条链上的挂单的撮合地址是同一个，并且处理高度范围存在交集，并且交集的高度满足指定数量；
3）当只撮合部分TOKEN时，剩余TOKEN可以继续撮合，直到挂单模板地址中的TOKEN小于等于费率值或者当前高度超过了有效高度时为止；
```

## 五、跨链交易逻辑：
```
1）锁定高度高的一方（假设为跨链交易方A），较验对端链的撮合交易中的撮合模板参数，是否与本端链的挂单模板参数一至（如秘密hash是否一至，TOKEN是否一至等），如果一至，则通过自已的私钥解密挂单模板中的原HASH加密数据，得到原HASH，然后将原HASH传给对端；可以采用多种途径传递给对端，如果跨链交易方A和跨链交易方B无法建立线下通讯，则可以产生一条交易（该交易的from和to都为撮合模板地址），将原HASH放在vchData中，该交易在跨链交易方A的链上（即A链）；
2）锁定高度低的一方（假设为跨链交易方B），在A链上监听到原HASH的交易，获得A链的原HASH（或者通过其它途径获得原HASH），跨链交易方B即可以将撮合模板地址B中的TOKEN转到相应的地址（包括转到挂单A的地址），该交易中需要包含原HASH A和原HASH B（原HASH B是跨链交易方B解密得到）；
3）跨链交易方A在B链上监听到上面的转帐交易，即可获得原HASH B，然后跨链交易方A就可以将撮合模板地址A中的TOKEN转到相应的地址（包括转到挂单B的地址），同样该交易中包含原HASH A和原HASH B，该步完成了跨链交易；
```

## 六、撮合模板地址需要转出的三条交易：
```
撮合模板地址A ：跨链交易方A完成（假设费率为0.2%）
1）撮合模板地址A  ->  挂单地址B，比例：99.8%
2）撮合模板地址A  ->  撮合地址，比例：0.1%
3）撮合模板地址A  ->  跨链交易地址A，比例：0.1%

撮合模板地址B ：跨链交易方B完成（假设费率为0.2%）
1）撮合模板地址B  ->  挂单地址A，比例：99.8%
2）撮合模板地址B  ->  撮合地址，比例：0.1%
3）撮合模板地址B  ->  跨链交易地址B，比例：0.1%

转帐数量计算：
a）转帐给买方地址的amount计算：(撮合数量-0.05*3)*(1-费率)
b）转帐给撮合方地址的amount计算：(撮合数量-0.05*3)*(费率/2)
c）转帐给跨链交易方地址的amount计算：撮合数量 - ((撮合数量-0.05*3)*(1-费率)+0.05) - ((撮合数量-0.05*3)*(费率/2)+0.05) - 0.05     （即：剩余数量-0.05）
注：需要严格按上面的公式计算，否则可能较验失败。

交易费率（必须）：0.05
交易顺序（必须）：转帐给买方地址、转帐给撮合方地址、转帐给跨链交易方地址
```

# 测试方法：
## 一、测试准备：
```
1）下载代码（分支dex-master）：
git clone https://github.com/mkfio/mkfio.git
git checkout dex-master

2）编译代码（带testnet参数，编译为测试网程序）
./INSTALL.sh testnet

3）添加目录及配置文件：
添加目录：.mkf
添加配置文件：bigbang.conf   （在.mkf目录下）
配置参数：
cryptonightaddress=1j6x8vdkkbnxe8qwjggfan9c8m8zhmez7gm3pznsqxgch3eyrwxby8eda
cryptonightkey=28efbfda61b473c37549d02784648d89fe21ff082b7a42da9ef97b0b83cdb1a9
listen4

4）启动程序：
$ mkf -daemon -debug

5）启动客户端：
$ mkf-cli

6）导入创世地址：
importprivkey f19c86f39741fe57cb2e0d5b9051787a1672437678c394ee2002979f6c247411 123
```

## 二、各个地址信息：
```
1）生成卖方（本端）挂单地址：
privkey: 12d00e8b46fbdc54cbf7f47f98a98bb3ea4843131f7ed2ffc11ad07405ca4f33
pubkey: b7465560cab12b80368e133c4c4ee04391b3463be73a6073f66914624b8ece96
address: 1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn

2）生成买方（对端）挂单地址：
privkey: 2c2bd21229865dc051f246492203ee09eea60d96ffb56073032a28b763eae667
pubkey: a110983d7b9d0055285080fa5ff7d8b2364cdab4503b9f917cb7af8e7234afac
address: 1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47

3）生成撮合者地址：
privkey: 47a090d85d8ff12f327e8fa6d238be0fd7de05a7b92083831e50593cec9c2eae
pubkey: a844944216eeb67c2766de8487691e50ad8612e8b10f42cf45c8d61074533a2b
address: 15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd

4）生成跨链交易者地址：
privkey: 43ff83b7063a3a3ff6b8c5a2d43ce14fdcfeec7b754ee83345ae7280e1a8c85d
pubkey: 89e15f230edeb9f4d2897eebd585f4414b06584e58982fa585055d598d2a9678
address: 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb
```

## 三、导入地址的私钥：
```
importprivkey 12d00e8b46fbdc54cbf7f47f98a98bb3ea4843131f7ed2ffc11ad07405ca4f33 123
importprivkey 2c2bd21229865dc051f246492203ee09eea60d96ffb56073032a28b763eae667 123
importprivkey 47a090d85d8ff12f327e8fa6d238be0fd7de05a7b92083831e50593cec9c2eae 123
importprivkey 43ff83b7063a3a3ff6b8c5a2d43ce14fdcfeec7b754ee83345ae7280e1a8c85d 123
```

## 四、生成秘密：
```
1）生成卖方秘密HASH：
原数据：b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef
秘密HASH：41f73534701f620ee8f48ecd61bb422fa9243ccc6ddda5e806f5858121c47268

注：使用makesha256 命令可以生成秘密HASH，生成的结果信息：
hexdata：为原数据
sha256：为hexdata数据经过sha256计算后的数据，该数据为挂单模板中的秘密HASH；

2）生成买方秘密HASH：
原数据：6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
秘密HASH：dfa313257be0216a498d2eb6e5a1939eb6168d4a9e3356cc20fb957d030b1ac5

3）生成原HASH加密数据：
将hexdata数据，经过aes加密，加密需要使用挂单地址和买方（对端）的挂单地址，本端挂单地址需要导入；

解锁地址：
unlockkey 1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn 123

生成加密数据：
aesencrypt 1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef

加密数据：42f30c39231e1a518e437df6a71e26535ef65f852fb879157bf9903b7d8065edc66eacec81eaef841c1052978b01340e
```

## 五、生成模板地址：
```
1）生成挂单模板地址：

挂单模板地址字段信息：
"seller_address":"1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn",
"coinpair":"bbc/mkf",
"price":10,
"fee": 0.002,
"secret_hash":"41f73534701f620ee8f48ecd61bb422fa9243ccc6ddda5e806f5858121c47268",
"secret_enc": ["42f30c39231e1a518e437df6a71e26535ef65f852fb879157bf9903b7d8065edc66eacec81eaef841c1052978b01340e"],
"valid_height": 300,
"sect_height": 10,
"match_address": ["15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd"],
"deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"]

添加挂单模板地址命令：
addnewtemplate dexorder '{"seller_address":"1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn","coinpair":"bbc/mkf","price":10,"fee": 0.002,"secret_hash":"41f73534701f620ee8f48ecd61bb422fa9243ccc6ddda5e806f5858121c47268","secret_enc": ["42f30c39231e1a518e437df6a71e26535ef65f852fb879157bf9903b7d8065edc66eacec81eaef841c1052978b01340e"],"valid_height": 300,"sect_height": 10,"match_address": ["15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd"],"deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"]}'

挂单模板地址：21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5
```

2）生成跨链交易模板地址：
```
跨链交易模板地址字段信息：
"match_address": "15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd",
"match_amount": 15,
"fee": 0.002,
"seller_order_address": "21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5",
"seller_address": "1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn",
"seller_deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"],
"seller_valid_height": 300,
"seller_sect_height": 10,
"buyer_order_address":"214066gfxcx75vmnk63dennhx55pzac42qwbrkadd7bzxmw72s2177eb3",
"buyer_address": "1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47",
"buyer_secret_hash":"dfa313257be0216a498d2eb6e5a1939eb6168d4a9e3356cc20fb957d030b1ac5",
"buyer_valid_height":320

添加跨链交易模板地址命令：
addnewtemplate dexmatch '{"match_address": "15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd","match_amount": 15,"fee": 0.002,"seller_order_address": "21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5","seller_address": "1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn","seller_deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"],"seller_valid_height": 300,"seller_sect_height": 10,"buyer_order_address":"214066gfxcx75vmnk63dennhx55pzac42qwbrkadd7bzxmw72s2177eb3","buyer_address": "1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47","buyer_secret_hash":"dfa313257be0216a498d2eb6e5a1939eb6168d4a9e3356cc20fb957d030b1ac5","buyer_valid_height":320}'

跨链交易模板地址：21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9
```

## 六、交易：
```
1）挂单交易：向挂单模板地址转帐
向挂单模板地址转帐：
sendfrom 20g053vhn4ygv9m8pzhevnjvtgbbqhgs66qv31ez39v9xbxvk0ynqmeyf 21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5 100

注：任何地址向挂单模板地址转帐都可以，帐转数量为需要交易的数量，但可能只有部分数量完成交易。

2）撮合交易：由撮合者完成交易，从挂单模板地址向撮合模板地址转帐，转帐TOKEN数为撮合模板地址中的交易数量。
解锁撮合者地址：
unlockkey 15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd 123
转帐给撮合模板地址：
sendfrom 21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 15 0.06
注：交易费最小为0.06

3）产生跨链交易：由跨链交易者产生交易，从撮合模板地址向买方地址转帐。
解锁跨链交易者地址：
unlockkey 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb 123
转帐给买方地址：
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47 14.8203 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
转帐给撮合方地址：
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd 0.01485 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
转帐给跨链交易方地址：
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb 0.01485 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7

转帐数量计算：
a）转帐给买方地址的amount计算：(撮合数量-0.05*3)*(1-费率)
b）转帐给撮合方地址的amount计算：(撮合数量-0.05*3)*(费率/2)
c）转帐给跨链交易方地址的amount计算：撮合数量 - ((撮合数量-0.05*3)*(1-费率)+0.05) - ((撮合数量-0.05*3)*(费率/2)+0.05) - 0.05     （即：剩余数量-0.05）
注：需要严格按上面的公式计算，否则可能较验失败。

交易费率（必须）：0.05
交易顺序（必须）：转帐给买方地址、转帐给撮合方地址、转帐给跨链交易方地址
```

## 七、所有命令集合：
```
importprivkey f19c86f39741fe57cb2e0d5b9051787a1672437678c394ee2002979f6c247411 123
importprivkey 12d00e8b46fbdc54cbf7f47f98a98bb3ea4843131f7ed2ffc11ad07405ca4f33 123
importprivkey 2c2bd21229865dc051f246492203ee09eea60d96ffb56073032a28b763eae667 123
importprivkey 47a090d85d8ff12f327e8fa6d238be0fd7de05a7b92083831e50593cec9c2eae 123
importprivkey 43ff83b7063a3a3ff6b8c5a2d43ce14fdcfeec7b754ee83345ae7280e1a8c85d 123

addnewtemplate dexorder '{"seller_address":"1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn","coinpair":"bbc/mkf","price":10,"fee": 0.002,"secret_hash":"41f73534701f620ee8f48ecd61bb422fa9243ccc6ddda5e806f5858121c47268","secret_enc": ["42f30c39231e1a518e437df6a71e26535ef65f852fb879157bf9903b7d8065edc66eacec81eaef841c1052978b01340e"],"valid_height": 300,"sect_height": 10,"match_address": ["15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd"],"deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"]}'

addnewtemplate dexmatch '{"match_address": "15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd","match_amount": 15,"fee": 0.002,"seller_order_address": "21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5","seller_address": "1jv78wjv22hmzcwv07bkkphnkj51y0kjc7g9rwdm05erwmr2n8tvh8yjn","seller_deal_address": ["1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb"],"seller_valid_height": 300,"seller_sect_height": 10,"buyer_order_address":"214066gfxcx75vmnk63dennhx55pzac42qwbrkadd7bzxmw72s2177eb3","buyer_address": "1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47","buyer_secret_hash":"dfa313257be0216a498d2eb6e5a1939eb6168d4a9e3356cc20fb957d030b1ac5","buyer_valid_height":320}'

unlockkey 1vszb4dxexw3bry2d2hvd87e8f964r834pr6f1xywdcp7ekcqpsmv08h3 123
sendfrom 1vszb4dxexw3bry2d2hvd87e8f964r834pr6f1xywdcp7ekcqpsmv08h3 21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5 100

unlockkey 15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd 123
sendfrom 21402e7hszzt1jheq3tmhvw1h1npm4c5rqc4qhkep08aeqbm5czpaerj5 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 15 0.06

unlockkey 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb 123
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 1njqk8wmenyvqs4cz7d8b9pjc6tsdhxtzza050a2n02eqpfcr22ggqg47 14.8203 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 15cx56x0gtv44bkt21yryg4m6nn81wtc7gkf6c9vwpvq1cgmm8jm7m5kd 0.01485 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
sendfrom 21802xgxyqnajgdb481cvge2vax8c8f2jwp2sqwgjw8y878q64t2rswz9 1f2b2n3asbm2rb99fk1c4wp069d0z91enxdz8kmqmq7f0w8tzw64hdevb 0.01485 0.05 -sm=b6103658b60234ade25b7389a08514b6803dff9c636dff92ef0edaa0f37e2eef -ss=6836ba9b8f40f968888a7376f657f97c53cfa8db02872e0f1daf8376cb80b1e7
```