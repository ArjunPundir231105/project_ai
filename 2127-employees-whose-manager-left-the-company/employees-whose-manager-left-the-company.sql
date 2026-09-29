SELECT A.employee_id
FROM Employees AS A
WHERE A.salary < 30000
  AND A.manager_id NOT IN (
      SELECT E.employee_id
      FROM Employees AS E
      JOIN Employees AS M
        ON E.employee_id = M.manager_id
  )
ORDER BY A.employee_id;