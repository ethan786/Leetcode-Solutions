# Write your MySQL query statement below
select name 
from customer 
where referee_id IS NULL or referee_id <> 2;