SELECT
    person_id AS id,
    COUNT(*) AS num
FROM (
    SELECT requester_id AS person_id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS person_id FROM RequestAccepted
) AS friends
GROUP BY person_id
ORDER BY num DESC
LIMIT 1;