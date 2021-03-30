
(cl:in-package :asdf)

(defsystem "motorcycle_gz-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "parameterData" :depends-on ("_package_parameterData"))
    (:file "_package_parameterData" :depends-on ("_package"))
  ))