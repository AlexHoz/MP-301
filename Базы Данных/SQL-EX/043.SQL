SELECT name
FROM battles
WHERE YEAR(date) NOT IN
(
SELECT launched
FROM ships
WHERE launched IS NOT NULL
)
