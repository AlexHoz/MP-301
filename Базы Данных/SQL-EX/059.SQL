SELECT i.P, isnull(i.M, 0) - isnull(o.M, 0) rem FROM
(SELECT point P, SUM(inc) M FROM income_o GROUP BY point) i,
(SELECT point P, SUM(out) M FROM outcome_o GROUP BY point) o
WHERE
i.P = o.P
UNION
SELECT point P, sum(inc) rem from income_o
where point not in (select point from outcome_o)
GROUP BY point
