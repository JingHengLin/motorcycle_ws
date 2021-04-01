;; Auto-generated. Do not edit!


(when (boundp 'motorcycle_gz::driveJoint)
  (if (not (find-package "MOTORCYCLE_GZ"))
    (make-package "MOTORCYCLE_GZ"))
  (shadow 'driveJoint (find-package "MOTORCYCLE_GZ")))
(unless (find-package "MOTORCYCLE_GZ::DRIVEJOINT")
  (make-package "MOTORCYCLE_GZ::DRIVEJOINT"))

(in-package "ROS")
;;//! \htmlinclude driveJoint.msg.html


(defclass motorcycle_gz::driveJoint
  :super ros::object
  :slots (_force _velocity_goal _velocity_current _direction _time ))

(defmethod motorcycle_gz::driveJoint
  (:init
   (&key
    ((:force __force) 0.0)
    ((:velocity_goal __velocity_goal) 0.0)
    ((:velocity_current __velocity_current) 0.0)
    ((:direction __direction) 0.0)
    ((:time __time) 0.0)
    )
   (send-super :init)
   (setq _force (float __force))
   (setq _velocity_goal (float __velocity_goal))
   (setq _velocity_current (float __velocity_current))
   (setq _direction (float __direction))
   (setq _time (float __time))
   self)
  (:force
   (&optional __force)
   (if __force (setq _force __force)) _force)
  (:velocity_goal
   (&optional __velocity_goal)
   (if __velocity_goal (setq _velocity_goal __velocity_goal)) _velocity_goal)
  (:velocity_current
   (&optional __velocity_current)
   (if __velocity_current (setq _velocity_current __velocity_current)) _velocity_current)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:serialization-length
   ()
   (+
    ;; float64 _force
    8
    ;; float64 _velocity_goal
    8
    ;; float64 _velocity_current
    8
    ;; float64 _direction
    8
    ;; float64 _time
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _force
       (sys::poke _force (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _velocity_goal
       (sys::poke _velocity_goal (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _velocity_current
       (sys::poke _velocity_current (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _direction
       (sys::poke _direction (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _force
     (setq _force (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _velocity_goal
     (setq _velocity_goal (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _velocity_current
     (setq _velocity_current (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _direction
     (setq _direction (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get motorcycle_gz::driveJoint :md5sum-) "84578ee7f01bae230834681aca563918")
(setf (get motorcycle_gz::driveJoint :datatype-) "motorcycle_gz/driveJoint")
(setf (get motorcycle_gz::driveJoint :definition-)
      "float64 force
float64 velocity_goal
float64 velocity_current
float64 direction
float64 time

")



(provide :motorcycle_gz/driveJoint "84578ee7f01bae230834681aca563918")


