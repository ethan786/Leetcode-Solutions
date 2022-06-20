# Write your MySQL query statement below

select x.employee_id from

(select employee_id from employees
where employee_id not in (select employee_id from salaries)

union all

select employee_id from salaries
where employee_id not in (select employee_id from employees)
) as x
order by x.employee_id;

;