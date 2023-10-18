// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph_classes.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_graph_5fclasses_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_graph_5fclasses_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4024000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4024004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_graph_5fclasses_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_graph_5fclasses_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_graph_5fclasses_2eproto;
class Node;
struct NodeDefaultTypeInternal;
extern NodeDefaultTypeInternal _Node_default_instance_;
class Relationship;
struct RelationshipDefaultTypeInternal;
extern RelationshipDefaultTypeInternal _Relationship_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Node final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Node) */ {
 public:
  inline Node() : Node(nullptr) {}
  ~Node() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Node(::google::protobuf::internal::ConstantInitialized);

  Node(const Node& from);
  Node(Node&& from) noexcept
    : Node() {
    *this = ::std::move(from);
  }

  inline Node& operator=(const Node& from) {
    CopyFrom(from);
    return *this;
  }
  inline Node& operator=(Node&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Node& default_instance() {
    return *internal_default_instance();
  }
  static inline const Node* internal_default_instance() {
    return reinterpret_cast<const Node*>(
               &_Node_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Node& a, Node& b) {
    a.Swap(&b);
  }
  inline void Swap(Node* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Node* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Node* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Node>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Node& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Node& from) {
    Node::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Node* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Node";
  }
  protected:
  explicit Node(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIsInUseFieldNumber = 1,
    kLabelFieldNumber = 5,
    kRemainingByteFieldNumber = 6,
    kIdFieldNumber = 2,
    kFirstRelationshipIdFieldNumber = 3,
    kFirstPropertyIdFieldNumber = 4,
  };
  // string is_in_use = 1;
  void clear_is_in_use() ;
  const std::string& is_in_use() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_is_in_use(Arg_&& arg, Args_... args);
  std::string* mutable_is_in_use();
  PROTOBUF_NODISCARD std::string* release_is_in_use();
  void set_allocated_is_in_use(std::string* ptr);

  private:
  const std::string& _internal_is_in_use() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_is_in_use(
      const std::string& value);
  std::string* _internal_mutable_is_in_use();

  public:
  // string label = 5;
  void clear_label() ;
  const std::string& label() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_label(Arg_&& arg, Args_... args);
  std::string* mutable_label();
  PROTOBUF_NODISCARD std::string* release_label();
  void set_allocated_label(std::string* ptr);

  private:
  const std::string& _internal_label() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_label(
      const std::string& value);
  std::string* _internal_mutable_label();

  public:
  // string remaining_byte = 6;
  void clear_remaining_byte() ;
  const std::string& remaining_byte() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_remaining_byte(Arg_&& arg, Args_... args);
  std::string* mutable_remaining_byte();
  PROTOBUF_NODISCARD std::string* release_remaining_byte();
  void set_allocated_remaining_byte(std::string* ptr);

  private:
  const std::string& _internal_remaining_byte() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_remaining_byte(
      const std::string& value);
  std::string* _internal_mutable_remaining_byte();

  public:
  // int32 id = 2;
  void clear_id() ;
  ::int32_t id() const;
  void set_id(::int32_t value);

  private:
  ::int32_t _internal_id() const;
  void _internal_set_id(::int32_t value);

  public:
  // int32 first_relationship_id = 3;
  void clear_first_relationship_id() ;
  ::int32_t first_relationship_id() const;
  void set_first_relationship_id(::int32_t value);

  private:
  ::int32_t _internal_first_relationship_id() const;
  void _internal_set_first_relationship_id(::int32_t value);

  public:
  // int32 first_property_id = 4;
  void clear_first_property_id() ;
  ::int32_t first_property_id() const;
  void set_first_property_id(::int32_t value);

  private:
  ::int32_t _internal_first_property_id() const;
  void _internal_set_first_property_id(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:Node)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<3, 6, 0, 41, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::internal::ArenaStringPtr is_in_use_;
    ::google::protobuf::internal::ArenaStringPtr label_;
    ::google::protobuf::internal::ArenaStringPtr remaining_byte_;
    ::int32_t id_;
    ::int32_t first_relationship_id_;
    ::int32_t first_property_id_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_graph_5fclasses_2eproto;
};// -------------------------------------------------------------------

class Relationship final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Relationship) */ {
 public:
  inline Relationship() : Relationship(nullptr) {}
  ~Relationship() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Relationship(::google::protobuf::internal::ConstantInitialized);

  Relationship(const Relationship& from);
  Relationship(Relationship&& from) noexcept
    : Relationship() {
    *this = ::std::move(from);
  }

  inline Relationship& operator=(const Relationship& from) {
    CopyFrom(from);
    return *this;
  }
  inline Relationship& operator=(Relationship&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Relationship& default_instance() {
    return *internal_default_instance();
  }
  static inline const Relationship* internal_default_instance() {
    return reinterpret_cast<const Relationship*>(
               &_Relationship_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Relationship& a, Relationship& b) {
    a.Swap(&b);
  }
  inline void Swap(Relationship* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Relationship* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Relationship* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Relationship>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Relationship& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Relationship& from) {
    Relationship::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Relationship* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Relationship";
  }
  protected:
  explicit Relationship(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRelationshipTypeFieldNumber = 3,
    kStartNodeIdFieldNumber = 1,
    kEndNodeIdFieldNumber = 2,
  };
  // string relationship_type = 3;
  void clear_relationship_type() ;
  const std::string& relationship_type() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_relationship_type(Arg_&& arg, Args_... args);
  std::string* mutable_relationship_type();
  PROTOBUF_NODISCARD std::string* release_relationship_type();
  void set_allocated_relationship_type(std::string* ptr);

  private:
  const std::string& _internal_relationship_type() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_relationship_type(
      const std::string& value);
  std::string* _internal_mutable_relationship_type();

  public:
  // int32 start_node_id = 1;
  void clear_start_node_id() ;
  ::int32_t start_node_id() const;
  void set_start_node_id(::int32_t value);

  private:
  ::int32_t _internal_start_node_id() const;
  void _internal_set_start_node_id(::int32_t value);

  public:
  // int32 end_node_id = 2;
  void clear_end_node_id() ;
  ::int32_t end_node_id() const;
  void set_end_node_id(::int32_t value);

  private:
  ::int32_t _internal_end_node_id() const;
  void _internal_set_end_node_id(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:Relationship)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<2, 3, 0, 38, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::internal::ArenaStringPtr relationship_type_;
    ::int32_t start_node_id_;
    ::int32_t end_node_id_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_graph_5fclasses_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Node

// string is_in_use = 1;
inline void Node::clear_is_in_use() {
  _impl_.is_in_use_.ClearToEmpty();
}
inline const std::string& Node::is_in_use() const {
  // @@protoc_insertion_point(field_get:Node.is_in_use)
  return _internal_is_in_use();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Node::set_is_in_use(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.is_in_use_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Node.is_in_use)
}
inline std::string* Node::mutable_is_in_use() {
  std::string* _s = _internal_mutable_is_in_use();
  // @@protoc_insertion_point(field_mutable:Node.is_in_use)
  return _s;
}
inline const std::string& Node::_internal_is_in_use() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.is_in_use_.Get();
}
inline void Node::_internal_set_is_in_use(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.is_in_use_.Set(value, GetArenaForAllocation());
}
inline std::string* Node::_internal_mutable_is_in_use() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.is_in_use_.Mutable( GetArenaForAllocation());
}
inline std::string* Node::release_is_in_use() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Node.is_in_use)
  return _impl_.is_in_use_.Release();
}
inline void Node::set_allocated_is_in_use(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.is_in_use_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.is_in_use_.IsDefault()) {
          _impl_.is_in_use_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Node.is_in_use)
}

// int32 id = 2;
inline void Node::clear_id() {
  _impl_.id_ = 0;
}
inline ::int32_t Node::id() const {
  // @@protoc_insertion_point(field_get:Node.id)
  return _internal_id();
}
inline void Node::set_id(::int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Node.id)
}
inline ::int32_t Node::_internal_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.id_;
}
inline void Node::_internal_set_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.id_ = value;
}

// int32 first_relationship_id = 3;
inline void Node::clear_first_relationship_id() {
  _impl_.first_relationship_id_ = 0;
}
inline ::int32_t Node::first_relationship_id() const {
  // @@protoc_insertion_point(field_get:Node.first_relationship_id)
  return _internal_first_relationship_id();
}
inline void Node::set_first_relationship_id(::int32_t value) {
  _internal_set_first_relationship_id(value);
  // @@protoc_insertion_point(field_set:Node.first_relationship_id)
}
inline ::int32_t Node::_internal_first_relationship_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.first_relationship_id_;
}
inline void Node::_internal_set_first_relationship_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.first_relationship_id_ = value;
}

// int32 first_property_id = 4;
inline void Node::clear_first_property_id() {
  _impl_.first_property_id_ = 0;
}
inline ::int32_t Node::first_property_id() const {
  // @@protoc_insertion_point(field_get:Node.first_property_id)
  return _internal_first_property_id();
}
inline void Node::set_first_property_id(::int32_t value) {
  _internal_set_first_property_id(value);
  // @@protoc_insertion_point(field_set:Node.first_property_id)
}
inline ::int32_t Node::_internal_first_property_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.first_property_id_;
}
inline void Node::_internal_set_first_property_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.first_property_id_ = value;
}

// string label = 5;
inline void Node::clear_label() {
  _impl_.label_.ClearToEmpty();
}
inline const std::string& Node::label() const {
  // @@protoc_insertion_point(field_get:Node.label)
  return _internal_label();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Node::set_label(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.label_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Node.label)
}
inline std::string* Node::mutable_label() {
  std::string* _s = _internal_mutable_label();
  // @@protoc_insertion_point(field_mutable:Node.label)
  return _s;
}
inline const std::string& Node::_internal_label() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.label_.Get();
}
inline void Node::_internal_set_label(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.label_.Set(value, GetArenaForAllocation());
}
inline std::string* Node::_internal_mutable_label() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.label_.Mutable( GetArenaForAllocation());
}
inline std::string* Node::release_label() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Node.label)
  return _impl_.label_.Release();
}
inline void Node::set_allocated_label(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.label_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.label_.IsDefault()) {
          _impl_.label_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Node.label)
}

// string remaining_byte = 6;
inline void Node::clear_remaining_byte() {
  _impl_.remaining_byte_.ClearToEmpty();
}
inline const std::string& Node::remaining_byte() const {
  // @@protoc_insertion_point(field_get:Node.remaining_byte)
  return _internal_remaining_byte();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Node::set_remaining_byte(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.remaining_byte_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Node.remaining_byte)
}
inline std::string* Node::mutable_remaining_byte() {
  std::string* _s = _internal_mutable_remaining_byte();
  // @@protoc_insertion_point(field_mutable:Node.remaining_byte)
  return _s;
}
inline const std::string& Node::_internal_remaining_byte() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.remaining_byte_.Get();
}
inline void Node::_internal_set_remaining_byte(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.remaining_byte_.Set(value, GetArenaForAllocation());
}
inline std::string* Node::_internal_mutable_remaining_byte() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.remaining_byte_.Mutable( GetArenaForAllocation());
}
inline std::string* Node::release_remaining_byte() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Node.remaining_byte)
  return _impl_.remaining_byte_.Release();
}
inline void Node::set_allocated_remaining_byte(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.remaining_byte_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.remaining_byte_.IsDefault()) {
          _impl_.remaining_byte_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Node.remaining_byte)
}

// -------------------------------------------------------------------

// Relationship

// int32 start_node_id = 1;
inline void Relationship::clear_start_node_id() {
  _impl_.start_node_id_ = 0;
}
inline ::int32_t Relationship::start_node_id() const {
  // @@protoc_insertion_point(field_get:Relationship.start_node_id)
  return _internal_start_node_id();
}
inline void Relationship::set_start_node_id(::int32_t value) {
  _internal_set_start_node_id(value);
  // @@protoc_insertion_point(field_set:Relationship.start_node_id)
}
inline ::int32_t Relationship::_internal_start_node_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.start_node_id_;
}
inline void Relationship::_internal_set_start_node_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.start_node_id_ = value;
}

// int32 end_node_id = 2;
inline void Relationship::clear_end_node_id() {
  _impl_.end_node_id_ = 0;
}
inline ::int32_t Relationship::end_node_id() const {
  // @@protoc_insertion_point(field_get:Relationship.end_node_id)
  return _internal_end_node_id();
}
inline void Relationship::set_end_node_id(::int32_t value) {
  _internal_set_end_node_id(value);
  // @@protoc_insertion_point(field_set:Relationship.end_node_id)
}
inline ::int32_t Relationship::_internal_end_node_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.end_node_id_;
}
inline void Relationship::_internal_set_end_node_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.end_node_id_ = value;
}

// string relationship_type = 3;
inline void Relationship::clear_relationship_type() {
  _impl_.relationship_type_.ClearToEmpty();
}
inline const std::string& Relationship::relationship_type() const {
  // @@protoc_insertion_point(field_get:Relationship.relationship_type)
  return _internal_relationship_type();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Relationship::set_relationship_type(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.relationship_type_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Relationship.relationship_type)
}
inline std::string* Relationship::mutable_relationship_type() {
  std::string* _s = _internal_mutable_relationship_type();
  // @@protoc_insertion_point(field_mutable:Relationship.relationship_type)
  return _s;
}
inline const std::string& Relationship::_internal_relationship_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.relationship_type_.Get();
}
inline void Relationship::_internal_set_relationship_type(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.relationship_type_.Set(value, GetArenaForAllocation());
}
inline std::string* Relationship::_internal_mutable_relationship_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.relationship_type_.Mutable( GetArenaForAllocation());
}
inline std::string* Relationship::release_relationship_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Relationship.relationship_type)
  return _impl_.relationship_type_.Release();
}
inline void Relationship::set_allocated_relationship_type(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.relationship_type_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.relationship_type_.IsDefault()) {
          _impl_.relationship_type_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Relationship.relationship_type)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_graph_5fclasses_2eproto_2epb_2eh