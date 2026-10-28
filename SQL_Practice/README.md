# SQL_Practice

MySQL 学习与练习。与 `C++_Practice` / `Java_Practice` / `Python_Practice` 同级，
用来收纳平时写的 SQL 脚本。

## 目录

| 目录 | 用途 |
| --- | --- |
| `Study/` | 跟着教程、文档、视频练的脚本 |
| `Homework/` | 课程作业与实验用的脚本 |

## 环境

- MySQL 8.x
- 字符集 `utf8mb4`，排序规则 `utf8mb4_0900_ai_ci`（MySQL 8 默认）
- 练习库命名：`practice_<主题>`；作业库命名：`hw_<实验号>`

## 文件命名

- 学习脚本：`NN_主题.sql`，例如 `01_select_basic.sql`、`02_join.sql`
- 作业脚本：`expNN_主题.sql`，例如 `exp01_create_table.sql`
- 序号补零，保证按文件名排序就是学习顺序

## 脚本头部模板

每个脚本开头写清楚这几行，方便以后回看：

```sql
-- 主题:
-- 日期:
-- 环境: MySQL 8.x (utf8mb4)
-- 数据库:
-- 说明:
```

## 运行方式

在 MySQL 客户端里用 `SOURCE`：

```sql
SOURCE Study/01_select_basic.sql;
```

或者命令行重定向：

```bash
mysql -u root -p < Study/01_select_basic.sql
```

## 约定

- **不要把密码、连接串、生产库地址写进 `.sql` 文件**，本仓库可能会公开
- 建表脚本尽量带 `DROP TABLE IF EXISTS`，方便反复重跑
- 涉及数据的实验，建表脚本和插数据脚本都保留一份，保证环境能重建
