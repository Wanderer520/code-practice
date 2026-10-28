create table emp(
    id int comment '编号',
    workno varchar(10) comment '工号',
    name varchar(10),
    gender char(1),
    age tinyint unsigned,
    idcard char(18) comment '身份证号',
    entrydate date comment '入职时间'
) comment '员工信息表';