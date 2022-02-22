这是一个高效的服务器，在作者电脑上能达到 11w QPS 同一电脑上Nginx只有3w QPS（作者电脑配置很低，tinywebserver仅1.2wQPS）

• 真正的异步编程（io_uring proactor）

• 多进程（一个Master多个Worker，配有进程异常退出复活机制）

• 字典树作字符匹配，零拷贝（mmap），

• request和response类处理GET和POST，cookie支持

• RAII机制的mysql连接池

• 安全独立的资源访问机制


环境：
需要内核版本5.12以上，同时安装Third_Part文件夹下的liburing，

开始：
安装liburing
安装mysql，建立数据库
create database Alyosha;

use Alyosha;
create table user(
username char(50) NULL,
passward char(50) NULL
)ENGINE=InnoDB;

insert into user(username,passward) values('aaa','123456');

create table problem(
    problemid char(50) NULL,
    codeid char(50) NULL,
    problemst char(50) NULL
)ENGINE=InnoDB;

insert into problem(problemid,codeid,problemst) values('001','0001','accept');

create table codeid(
    name char(50) NULL,
    nowid char(50) NULL
)ENGINE=InnoDB;

insert into codeid(name,nowid) values('aaa','0002');

exit;

编译项目：
make

配置：
数据库密码，以及端口，在config.txt文件夹中修改

运行：
sudo ./Alyosha

登录测试：
浏览器访问http://localhost:9856
输入用户名和密码
点击login后按F12可在浏览器命令行下看到{'aaa':'ok'}

性能测试：
# Third_Part/webbench-1.5目录下
./webbench -c 10500 -t 5 http://192.168.1.6:9856/


这个服务器设计目标是作为一个在低配电脑打比赛时的oj使用（5小时，15个题左右，大约20w人同时访问），以解决部分普通高校想要组织icpc这种大型比赛的想法（比如我校SUSE-.-）
所有设计为了实现这个目标的，所以有一些不完善的地方，（主要是我懒得写那么多代码，这个服务器是可以完善支持这些功能的。。。）

一切都是为了高并发

所有放在assets文件夹的文件都可以被GET直接访问到，
服务器运行期间想要添加文件，需要重启服务器（懒得写热更新-.-）
如果你想某个文件在某日期之后才能访问到，你可以在filterHttpStatus(HttpStatus* status)中进行筛选(这个函数位于base_server/ServerManager.cpp)
assets的文件名不要太长了（路径+文件名不要大于200个字符），不然会出错，
也不要使用中文文件名或路径（存储名字用的是字段树）（如果你想支持长文件名，可以去http/tire.h中修改TIRE_MAX_COUNT，改大一点就行了，TIRE_MAX_COUNT的意思是所有节点的数量上线，因为存储文件名用的是字典树，如果你学过字典树，你应该懂这是什么意思）

src/core的里面的代码是可以单独编译运行的(在core目录下直接make)，这个文件夹包含服务器的所有io逻辑和进程逻辑，他是整个服务器的核心。通过调试core，你可以知道服务器大体运行流程，单独core可以实现一个基本的,只回复OK的服务器

src/http也是可以编译运行的(在http目录下直接make)，是http请求的部分解析和文件访问相关的代码，core+http可以实现一个资源服务器

base_server sql config等是后端代码需要用的一些类

整个oj的后端代码在server文件夹

src/core和src/http只使用了极少的c++特性，未使用stl，保证核心部分代码足够简单，内存管理简单化，方便找bug，

base_server和server等就比较放飞自我了。(forwark完美转发yyds)

# Alyosha-Online-Judge
"# Alyosha-Online-Judge" 
