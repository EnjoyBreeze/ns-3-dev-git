#ifndef TDMA_MAC_H
#define TDMA_MAC_H

#include "ns3/object.h"
#include "ns3/event-id.h"
#include "ns3/packet.h"
#include "ns3/nstime.h"
#include "ns3/log.h"
// Add a doxygen group for this module.
// If you have more than one file, this should be in only one of them.
/**
 * @defgroup new-module Description of the new-module
 */

namespace ns3
{

// Each class should be documented using Doxygen,
// and have an @ingroup new-module directive

/* ... */
class TdmaMac : public Object
{
public:
  static TypeId GetTypeId (void);
  TdmaMac ();
  virtual ~TdmaMac ();

  /// 设置每个时隙的持续时间（例如：20 毫秒）
  void SetSlotDuration (Time slotDuration);

  /// 为该节点设置标识符，用于日志等
  void SetNodeId (uint32_t id);

  /// 将数据包加入发送队列（此处示例直接记录日志）
  void Enqueue (Ptr<Packet> pkt);

  /// 启动 TDMA MAC 调度
  void Start ();

private:
  /// 定时器回调，模拟时隙切换
  void ScheduleNextSlot ();

  uint32_t m_nodeId;     //!< 节点标识
  Time     m_slotDuration;   //!< 时隙持续时间
  uint32_t m_slotNumber; //!< 当前时隙号
  EventId  m_slotEvent;  //!< 用于轮转时隙的调度事件
};
} // namespace ns3

#endif // NEW_MODULE_H
