
(cl:in-package :asdf)

(defsystem "motorcycle_gz-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "input" :depends-on ("_package_input"))
    (:file "_package_input" :depends-on ("_package"))
  ))