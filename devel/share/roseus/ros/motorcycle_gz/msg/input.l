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
  :slots (_v _d _t ))

(defmethod motorcycle_gz::input
  (:init
   (&key
    ((:v __v) 0)
    ((:d __d) 0.0)
    ((:t __t) 0)
    )
   (send-super :init)
   (setq _v (round __v))
   (setq _d (float __d))
   (setq _t (round __t))
   self)
  (:v
   (&optional __v)
   (if __v (setq _v __v)) _v)
  (:d
   (&optional __d)
   (if __d (setq _d __d)) _d)
  (:t
   (&optional __t)
   (if __t (setq _t __t)) _t)
  (:serialization-length
   ()
   (+
    ;; int32 _v
    4
    ;; float64 _d
    8
    ;; int32 _t
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _v
       (write-long _v s)
     ;; float64 _d
       (sys::poke _d (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _t
       (write-long _t s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _v
     (setq _v (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _d
     (setq _d (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _t
     (setq _t (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get motorcycle_gz::input :md5sum-) "d20864dc5c2c2035946b751aab74d0f1")
(setf (get motorcycle_gz::input :datatype-) "motorcycle_gz/input")
(setf (get motorcycle_gz::input :definition-)
      "int32 v
float64 d
int32 t

")



(provide :motorcycle_gz/input "d20864dc5c2c2035946b751aab74d0f1")


