#include "mainwindow.h"
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDatabase>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //添加MYSQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //数据库对象
    //设置数据库
    db.setDatabaseName("./translation.db");
    //打开数据库
    if( !db.open() )
    {
        //数据库打开失败
        qDebug("db open fail");
        return -1;
    }
    QSqlQuery query;
//    query.exec("drop table word");
    query.exec("create table word(English QString, Chinese QString, study int)");//创建表word

#if 0
    QString str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("hello").arg("你好").arg(0);
    query.exec(str); //执行插入操作

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("apple").arg("苹果").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("banana").arg("香蕉").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("watermelon").arg("西瓜").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("abandon").arg("抛弃").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("ability").arg("技能").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("abnormal").arg("不正常的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("about").arg("关于").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("abroad").arg("在国外").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("above").arg("在上面").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("absence").arg("突然的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("absolute").arg("绝对的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("absurd").arg("可笑的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("accept").arg("接受").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("accident").arg("事故").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("access").arg("进入").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("acclaim").arg("喝彩").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("accompany").arg("陪伴").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("accord").arg("一致").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("account").arg("账户").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("actor").arg("男演员").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("action").arg("行动").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("add").arg("增加").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("address").arg("地址").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("advance").arg("前进").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("advice").arg("意见").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("affect").arg("影响").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("afford").arg("承担得起").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("after").arg("后来").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("agent").arg("代理人").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("airplane").arg("飞机").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("airship").arg("飞艇").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("alien").arg("外国人").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("alike").arg("相同").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("allow").arg("允许").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("aloud").arg("大声地").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("although").arg("虽然").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("always").arg("总是").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("amaze").arg("使惊奇").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("amuse").arg("逗乐").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("animal").arg("动物").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("annual").arg("年度的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("answer").arg("答复").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("anti").arg("反对").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("antique").arg("古老的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("apiece").arg("每个").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("appeal").arg("呼吁").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("appeal").arg("出现").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("append").arg("增补").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("appoint").arg("任命").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("area").arg("地区").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("army").arg("军队").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("array").arg("排列").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("assist").arg("帮助").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("assert").arg("断言").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("atlas").arg("地图册").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("atom").arg("原子").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("attract").arg("吸引").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("autumn").arg("秋天").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("avert").arg("避免").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("aware").arg("明白的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("baby").arg("婴儿").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("back").arg("后面的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bag").arg("袋子").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("ball").arg("水斗").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bait").arg("诱饵").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("ballot").arg("投票").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bandage").arg("绷带").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bank").arg("银行").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("banner").arg("旗帜").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bare").arg("空的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("barrier").arg("屏障").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("base").arg("基础").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("basis").arg("基础").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("battle").arg("战斗").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bay").arg("海湾").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bean").arg("斗").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("beat").arg("敲").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("beet").arg("甜菜").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bee").arg("蜜蜂").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("beg").arg("乞求").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bend").arg("弯曲").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("billow").arg("巨浪").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("blade").arg("刀口").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("boar").arg("野猪").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("boon").arg("方便").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("brave").arg("勇敢的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("breed").arg("繁殖").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("bubble").arg("冒泡").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("cactus").arg("仙人掌").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("calender").arg("日历").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("canteen").arg("食堂").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("cash").arg("现金").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("ceremony").arg("典礼").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("change").arg("变化").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("cherish").arg("爱护").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("data").arg("资料").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("debate").arg("争论").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("deisre").arg("愿望").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("deter").arg("挡住").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("develop").arg("发展").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("doer").arg("实干者").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("dreamy").arg("奇妙的").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("eject").arg("赶出").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("embank").arg("围栏").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("endanger").arg("危害").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("enjoy").arg("喜爱").arg(0);
    query.exec(str);

    str = QString("insert into word(English, Chinese, study) values('%1', '%2', '%3')").arg("escape").arg("逃跑").arg(0);
    query.exec(str);


#endif


    return a.exec();
}
