--Задание 77
WITH t AS
(
  SELECT date, count(DISTINCT trip_no) AS count_trip
  FROM Pass_in_trip
  WHERE trip_no IN 
  (
    SELECT trip_no FROM trip WHERE town_from = 'Rostov'
  )
  GROUP BY date
)

SELECT count_trip, date
FROM t
WHERE count_trip = 
(
  SELECT max(count_trip) FROM t
)
