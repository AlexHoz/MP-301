SELECT point, SUM(abs)
FROM(
SELECT point, SUM(isnull(inc, 0))
FROM income_o
WHERE date < '2001.04.15'
GROUP BY point
UNION
SELECT point, -1 * SUM(isnull(out, 0))
FROM Outcome_o
WHERE date < '2001.04.15'
GROUP BY point
) a(point, abs)
GROUP BY point
