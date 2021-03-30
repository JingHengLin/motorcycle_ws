;; Auto-generated. Do not edit!


(when (boundp 'motorcycle_gz::parameterData)
  (if (not (find-package "MOTORCYCLE_GZ"))
    (make-package "MOTORCYCLE_GZ"))
  (shadow 'parameterData (find-package "MOTORCYCLE_GZ")))
(unless (find-package "MOTORCYCLE_GZ::PARAMETERDATA")
  (make-package "MOTORCYCLE_GZ::PARAMETERDATA"))

(in-package "ROS")
;;//! \htmlinclude parameterData.msg.html


(defclass motorcycle_gz::parameterData
  :super ros::object
  :slots (_force _velocity _direction _time ))

(defmethod motorcycle_gz::parameterData
  (:init
   (&key
    ((:force __force) 0.0)
    ((:velocity __velocity) 0.0)
    ((:direction __direction) 0.0)
    ((:time __time) 0.0)
    )
   (send-super :init)
   (setq _force (float __force))
   (setq _velocity (float __velocity))
   (setq _direction (float __direction))
   (setq _time (float __time))
   self)
  (:force
   (&optional __force)
   (if __force (setq _force __force)) _force)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
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
    ;; float64 _velocity
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
     ;; float64 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64 _velocity
     (setq _velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _direction
     (setq _direction (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get motorcycle_gz::parameterData :md5sum-) "ea51df68025e04a7c8e74f0d28f60b43")
(setf (get motorcycle_gz::parameterData :datatype-) "motorcycle_gz/parameterData")
(setf (get motorcycle_gz::parameterData :definition-)
      "float64 force
float64 velocity
float64 direction
float64 time

")



(provide :motorcycle_gz/parameterData "ea51df68025e04a7c8e74f0d28f60b43")


