
(cl:in-package :asdf)

(defsystem "motorcycle_gz-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "driveJoint" :depends-on ("_package_driveJoint"))
    (:file "_package_driveJoint" :depends-on ("_package"))
  ))