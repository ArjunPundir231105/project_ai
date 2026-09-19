# Write your MySQL query statement below
select round(100*avg(order_date = customer_pref_delivery_date),2)  AS immediate_percentage
from (
select *,
row_number() over (
partition by customer_id
order by order_date
) as rn 
from Delivery
) as t 
where rn = 1 ;
