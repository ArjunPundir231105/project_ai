# Write your MySQL query statement below
Select customer_id, Count(visit_id) as count_no_trans
from Visits
where visit_id not in(
Select distinct visit_id 
from Transactions)
GROUP BY customer_id;
