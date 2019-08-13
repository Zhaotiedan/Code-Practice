use master
go
create database COSSS
go
use COSSS
go
--仓库表

create table Base
(
Bno int primary key,
Bname  varchar(50) unique not null,
Bnum int,
Btel char(20) unique not null 
)
insert into Base values(01,'灯泡库',100,'12345')
go
--货物表
create table Goods
(
Gno int primary key,           --货物号
Gname varchar(20) not null,    --货物名
Gprice int not null,          --货物单价
Gbnum int references Base(Bno),--货物所在仓库
)
insert into Goods values(01,'灯泡',1,01)

--部门表
create table Department
(
Dno int primary key,--部门号
Dname varchar(50)  not null,--部门名
Dtel char(20) unique not null, --部门联系方式
Daddr varchar(50) not null,   --部门地址
)
insert into Department values(01,'信息部','123456','1厂三楼101办公室')
insert into Department values(02,'卫生部','123457','1厂三楼102办公室')
insert into Department values(03,'订单管理部','123458','1厂三楼103办公室')
insert into Department values(04,'顾客管理部','123459','1厂三楼104办公室')
go
--员工表
create table Employe 
(
Eno int primary key,--员工号
Ename varchar(50)  not null,--员工名
Eage int not null,--员工年龄
Ebno int references Department(Dno),  --员工部门号参照部门表里的主部门号
Ework varchar(50) ,   --员工岗位
Etel char(20) unique not null --员工联系方式

)
insert into Employe values(222,'张三 ', 20 , 02 ,'管理仓库' ,'110120119')
insert into Employe values(333,'小张 ', 21 , 03 ,'管理订单' ,'110120110')

go
--顾客表
create table Custom 
(
Cno int primary key,--顾客号
Cname varchar(20) not null,--顾客名
Ctle char(20) unique not null,--顾客联系方式
Caddr varchar(50) not null,  --顾客地址
)
insert into Custom values(01,'李四','15486597325','东大街一号')
insert into Custom values(02,'王五','15486597335','东大街二号')
go
--订单细节表
  create table Detail
 (
 Dono int primary key ,    --对应订单号
 Dgno int references Goods(Gno),                 --货物号
 Dgname varchar(20) ,      --货物名
 Dgprice  int ,  --货物单件价格
 Dgnum int not null,                              --货物数量
 )
insert into Detail values(01,01,'螺丝',1,2)
--订单表
 create table Orders
(
Ono int references Detail(Dono) primary key,--订单号
Ocno int references Custom(Cno),--订单的顾客号
Oeno int references Employe(Eno),--订单负责人编号
Oin varchar(10) not null,      --订单对应发票号
Omoney int not null,           --订单总金额
Opway varchar(30) not null,           --支付方式
Opnum varchar(20),                    --支付账号
Odata varchar(30) not null,--订货日期
Ogddata varchar(30) not null,--交货日期
 )
 create table sump            
 (
 sumono int primary key,
 sumprice int
 )
 insert
 into sump(sumono,sumprice)
 select Dono,sum(Dgprice*Dgnum)
 from Detail
 group by Dono
 select * from Detail
 select * from sump
 
 declare @x int
set @x =(select sumprice from sump where sumono=01)
print @x
 insert into Orders values(01,01,333,'1234',@x,'信用卡','123456','2019.1.2','2019.1.3')
  select * from Orders
 go
 
 


---登录表
create table logins
(

Demonum varchar(20) not null,
DemoPwd varchar(50) not null,
)
insert into logins values('admin','123')
insert into logins values('sn','123')
go

