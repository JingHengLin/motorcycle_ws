// Auto-generated. Do not edit!

// (in-package motorcycle_gz.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class input {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.v = null;
      this.t = null;
    }
    else {
      if (initObj.hasOwnProperty('v')) {
        this.v = initObj.v
      }
      else {
        this.v = 0;
      }
      if (initObj.hasOwnProperty('t')) {
        this.t = initObj.t
      }
      else {
        this.t = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type input
    // Serialize message field [v]
    bufferOffset = _serializer.int32(obj.v, buffer, bufferOffset);
    // Serialize message field [t]
    bufferOffset = _serializer.int32(obj.t, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type input
    let len;
    let data = new input(null);
    // Deserialize message field [v]
    data.v = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [t]
    data.t = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'motorcycle_gz/input';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8f20aea9a85b7f60df8ca357388922ad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 v
    int32 t
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new input(null);
    if (msg.v !== undefined) {
      resolved.v = msg.v;
    }
    else {
      resolved.v = 0
    }

    if (msg.t !== undefined) {
      resolved.t = msg.t;
    }
    else {
      resolved.t = 0
    }

    return resolved;
    }
};

module.exports = input;
