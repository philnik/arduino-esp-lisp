(defun get-file (filename)
  (let ((x (open filename)))
    (when x
      (loop for line = (read-line x nil)
     while line do (list line)))
    (close x)))

(with-open-file (stream "arduino.el")
  (do ((line (read-line stream nil)
       (read-line stream nil)))
       ((null line))
       (print line)))

(with-open-file (f "/home/me/arduino/arduino.lib" :direction :output
                              :if-exists :append
                              :if-does-not-exist :create)
    (write-sequence "hello~%" f))


(with-open-file (stream "arduino.el")
  (with-open-file (f "/home/me/arduino/arduino1.lib" :direction :output
						    :if-exists :append
						    :if-does-not-exist :create)
    (do ((line (read-line stream nil)
	       (read-line stream nil)))
	((null line))
      (print line)
      (let ((l (format nil "\"~a\"~%" line)))
	(write-sequence l f)))))
  

(with-open-file (f "/home/me/arduino/arduino.lib" :direction :output
                              :if-exists :append
                              :if-does-not-exist :create)
    (write-sequence "hello~%" f))






(get-file "arduino.el")


(uiop:read-file-string "arduino.el")
