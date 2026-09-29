# Write your MySQL query statement below
(
Select t.name as results
from (
Select 
        Mr.movie_id,
        Mr.user_id,
        Mr.rating,
        Mr.created_at,
        M.title,
        U.name
from MovieRating as Mr
join 
Movies as M
on Mr.movie_id = M.movie_id
join 
Users as U
on Mr.user_id = U.user_id
) as t
group by t.name
ORDER BY COUNT(t.movie_id) DESC, t.name ASC
limit 1
)

UNION ALL
(
Select t.title as results
from (
Select 
        Mr.movie_id,
        Mr.user_id,
        Mr.rating,
        Mr.created_at,
        M.title,
        U.name
from MovieRating as Mr
join 
Movies as M
on Mr.movie_id = M.movie_id
join 
Users as U
on Mr.user_id = U.user_id
) as t
where created_at >= '2020-02-01'
and created_at <= '2020-02-29'
group by t.title
order by avg(t.rating) desc, t.title asc
limit 1
);
