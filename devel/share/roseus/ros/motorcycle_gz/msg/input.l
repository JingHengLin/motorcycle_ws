;; Auto-generated. Do not edit!


(when (boundp 'motorcycle_gz::input)
  (if (not (find-package "MOTORCYCLE_GZ"))
    (make-package "MOTORCYCLE_GZ"))
  (shadow 'input (find-package "MOTORCYCLE_GZ")))
(unless (find-package "MOTORCYCLE_GZ::INPUT")
  (make-package "MOTORCYCLE_GZ::INPUT"))

(in-package "ROS")
;;//! \htmlinclude input.msg.html


(defclass motorcycle_gz::input
  :super ros::object
  :slots (_y ))

(defmethod motorcycle_gz::input
  (:init
   (&key
    ((:y __y) 0)
    )
   (send-super :init)
   (setq _y (round __y))
   self)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; int32 _y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _y
       (write-long _y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get motorcycle_gz::input :md5sum-) "48a1903b27e436ce72db71499e9e0169")
(setf (get motorcycle_gz::input :datatype-) "motorcycle_gz/input")
(setf (get motorcycle_gz::input :definition-)
      "int32 y

")



(provide :motorcycle_gz/input "48a1903b27e436ce72db71499e9e0169")


