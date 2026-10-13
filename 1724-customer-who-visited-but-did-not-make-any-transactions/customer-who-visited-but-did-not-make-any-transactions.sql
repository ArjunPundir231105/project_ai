# Write your MySQL query statement below
Select distinct customer_id, count(*) as count_no_trans
from Visits as V
left join Transactions as T
on V.visit_id = T.visit_id
where transaction_id is NULL
GROUP BY V.customer_id;