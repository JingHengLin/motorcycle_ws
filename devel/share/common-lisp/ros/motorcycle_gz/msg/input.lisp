; Auto-generated. Do not edit!


(cl:in-package motorcycle_gz-msg)


;//! \htmlinclude input.msg.html

(cl:defclass <input> (roslisp-msg-protocol:ros-message)
  ((v
    :reader v
    :initarg :v
    :type cl:integer
    :initform 0)
   (t
    :reader t
    :initarg :t
    :type cl:integer
    :initform 0))
)

(cl:defclass input (<input>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <input>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'input)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motorcycle_gz-msg:<input> is deprecated: use motorcycle_gz-msg:input instead.")))

(cl:ensure-generic-function 'v-val :lambda-list '(m))
(cl:defmethod v-val ((m <input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motorcycle_gz-msg:v-val is deprecated.  Use motorcycle_gz-msg:v instead.")
  (v m))

(cl:ensure-generic-function 't-val :lambda-list '(m))
(cl:defmethod t-val ((m <input>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motorcycle_gz-msg:t-val is deprecated.  Use motorcycle_gz-msg:t instead.")
  (t m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <input>) ostream)
  "Serializes a message object of type '<input>"
  (cl:let* ((signed (cl:slot-value msg 'v)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 't)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <input>) istream)
  "Deserializes a message object of type '<input>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'v) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 't) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<input>)))
  "Returns string type for a message object of type '<input>"
  "motorcycle_gz/input")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'input)))
  "Returns string type for a message object of type 'input"
  "motorcycle_gz/input")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<input>)))
  "Returns md5sum for a message object of type '<input>"
  "8f20aea9a85b7f60df8ca357388922ad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'input)))
  "Returns md5sum for a message object of type 'input"
  "8f20aea9a85b7f60df8ca357388922ad")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<input>)))
  "Returns full string definition for message of type '<input>"
  (cl:format cl:nil "int32 v~%int32 t~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'input)))
  "Returns full string definition for message of type 'input"
  (cl:format cl:nil "int32 v~%int32 t~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <input>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <input>))
  "Converts a ROS message object to a list"
  (cl:list 'input
    (cl:cons ':v (v msg))
    (cl:cons ':t (t msg))
))
