# Write your MySQL query statement below

WITH cte As
(SELECT e.name AS Employee ,e.salary, d.name AS Department,MAX(e.salary) OVER(PARTITION BY e.departmentId) As max_salary
FROM Employee e
LEFT JOIN Department d
ON e.departmentId=d.id)

SELECT department ,Employee,Salary
FROM cte
WHERE salary=Max_Salary
