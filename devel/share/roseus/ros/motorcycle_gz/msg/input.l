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
  :slots (_force _d _t ))

(defmethod motorcycle_gz::input
  (:init
   (&key
    ((:force __force) 0.0)
    ((:d __d) 0.0)
    ((:t __t) 0.0)
    )
   (send-super :init)
   (setq _force (float __force))
   (setq _d (float __d))
   (setq _t (float __t))
   self)
  (:force
   (&optional __force)
   (if __force (setq _force __force)) _force)
  (:d
   (&optional __d)
   (if __d (setq _d __d)) _d)
  (:t
   (&optional __t)
   (if __t (setq _t __t)) _t)
  (:serialization-length
   ()
   (+
    ;; float64 _force
    8
    ;; float64 _d
    8
    ;; float64 _t
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _force
       (sys::poke _force (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _d
       (sys::poke _d (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _t
       (sys::poke _t (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _force
     (setq _force (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _d
     (setq _d (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _t
     (setq _t (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get motorcycle_gz::input :md5sum-) "cb0e4b0c846c6cafc467bc7405eac5f2")
(setf (get motorcycle_gz::input :datatype-) "motorcycle_gz/input")
(setf (get motorcycle_gz::input :definition-)
      "float64 force
float64 d
float64 t

")



(provide :motorcycle_gz/input "cb0e4b0c846c6cafc467bc7405eac5f2")


