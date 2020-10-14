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
