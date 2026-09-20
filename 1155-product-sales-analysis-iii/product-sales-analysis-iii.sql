# Write your MySQL query statement below
select S.product_id, t.first_year, S.quantity , S.price
from Sales as S
join
(
select product_id, min(year) as first_year
from Sales
group by product_id
) as t
on t.product_id = S.product_id
and t.first_year = S.year;
