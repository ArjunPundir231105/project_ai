# Write your MySQL query statement below
Select A.id
from Weather as A
join Weather as B
on datediff(A.recordDate,B.recordDate) = 1
where A.temperature > B.temperature;