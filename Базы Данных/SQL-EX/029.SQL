SELECT t.point, t.date, SUM(t.inc), sum(t.out)
FROM (SELECT point, date, inc, null AS out
FROM Income_o  
UNION 
SELECT point, date, null AS inc, Outcome_o.out
FROM Outcome_o) AS t
GROUP BY t.point, t.date
