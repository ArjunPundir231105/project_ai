# Write your MySQL query statement below
Select name
from Employee
where id in
(
    Select managerId as id 
    from Employee
    group by managerId
    having count(id) >= 5
);