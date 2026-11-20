# Write your MySQL query statement below
with CTE AS(
    select 
       person_name,turn,
       sum(weight) over (order by turn) as Total_Weight
    from Queue

)
select person_name
from CTE
where Total_Weight<=1000
order by turn DESC
limit 1;
