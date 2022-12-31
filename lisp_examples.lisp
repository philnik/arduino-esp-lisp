(defun parse-gps (gps-string)
  (let ((parts (split gps-string ",")))
    (cond
      ((= (length parts) 15)
       (let ((lat (parse-coord (nth 2 parts)))
             (lat-dir (nth 3 parts))
             (lon (parse-coord (nth 4 parts)))
             (lon-dir (nth 5 parts)))
         (list lat lat-dir lon lon-dir)))
      (t nil))))

(defun parse-coord (coord)
  (let ((degrees (floor (float (nth 0 coord))))
        (minutes (float (nth 1 coord)))
        (seconds (float (nth 2 coord))))
    (+ (* degrees 100) (/ minutes 60) (/ seconds 3600))))

(print (parse-gps "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47"))

(with-serial (str 3 96)(loop(print (read-line str))))
(+ 1 1)
