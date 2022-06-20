# Write your MySQL query statement below

select sell_date
     , count(distinct product) num_sold 
     , group_concat(distinct product order by product asc separator ',') products
from activities
group by sell_date
order by sell_date;

# select sell_date
# 	 , count(distinct product) num_sold
# 	 , group_concat(distinct product order by product asc separator ',') products
# from activities
# group by sell_date
# order by sell_date;