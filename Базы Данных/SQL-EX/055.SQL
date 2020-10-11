Select c.class, min(launched)
from ships s left join classes c on s.class = c.class
group by c.class
UNION 
SELECT c.class, null
FROM classes c 
WHERE ( SELECT COUNT(0) from ships s WHERE c.class = s.class) = 0
