--Задание 29
SELECT point, date, sum(inc), sum(out)
FROM
(
  SELECT point, date, inc, null as out
  FROM Income_o
  UNION
  SELECT point, date, null as inc, out
  FROM Outcome_o
) AS Incomes
GROUP BY point, date

--Задание 30
SELECT point, date, sum(out) AS outcome, sum(inc) AS income
FROM
(
  SELECT point, date, inc, null as out
  FROM Income
  UNION ALL
  SELECT point, date, null as inc, out
  FROM Outcome
) AS Incomes
GROUP BY point, date

--Задание 96
WITH r_v AS (
  SELECT b_v_id
  FROM utb
  GROUP BY b_v_id
  HAVING count(b_v_id) > 1
  AND b_v_id
  IN
  (
    SELECT v_id
    FROM utv
    WHERE v_color = 'R'
  )
),
b_q AS (
  SELECT b_q_id
  FROM utb
  GROUP BY b_q_id, b_v_id 
  HAVING b_v_id
  IN
  (
    SELECT v_id
    FROM utv
    WHERE v_color = 'B'
  )
)

SELECT v_name
FROM utv
WHERE v_id
IN
(
  SELECT DISTINCT b_v_id
  FROM utb
  WHERE b_v_id
  IN
  (
    SELECT *
    FROM R
  )
  AND  b_q_id
  IN
  (
    SELECT *
    FROM B
  )
)
