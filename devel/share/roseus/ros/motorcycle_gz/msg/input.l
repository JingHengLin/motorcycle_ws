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
  :slots (_v _t ))

(defmethod motorcycle_gz::input
  (:init
   (&key
    ((:v __v) 0)
    ((:t __t) 0)
    )
   (send-super :init)
   (setq _v (round __v))
   (setq _t (round __t))
   self)
  (:v
   (&optional __v)
   (if __v (setq _v __v)) _v)
  (:t
   (&optional __t)
   (if __t (setq _t __t)) _t)
  (:serialization-length
   ()
   (+
    ;; int32 _v
    4
    ;; int32 _t
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _v
       (write-long _v s)
     ;; int32 _t
       (write-long _t s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _v
     (setq _v (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _t
     (setq _t (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get motorcycle_gz::input :md5sum-) "8f20aea9a85b7f60df8ca357388922ad")
(setf (get motorcycle_gz::input :datatype-) "motorcycle_gz/input")
(setf (get motorcycle_gz::input :definition-)
      "int32 v
int32 t

")



(provide :motorcycle_gz/input "8f20aea9a85b7f60df8ca357388922ad")


