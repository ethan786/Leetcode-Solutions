# Write your MySQL query statement below
select name from salesperson where sales_id not in 
(
    select sales_id from orders as o left join company as c
    on o.com_id = c.com_id 
    
    where name = "RED"
    
);