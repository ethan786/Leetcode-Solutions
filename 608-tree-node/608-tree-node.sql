# Write your MySQL query statement below

select id, 'Root' as type from tree
where p_id is NULL

union 

select id, 'Inner' as type from tree
where id in (select distinct p_id from tree) and p_id is not NULL 

union 

select id, 'Leaf' as type from tree
where id not in (select distinct p_id from tree where p_id is not NULL) and  p_id is not NULL ; 

;