#include "tdma-mac.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
namespace ns3
{
    NS_LOG_COMPONENT_DEFINE ("TdmaMac");
/* ... */
TypeId TdmaMac::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TdmaMac")
    .SetParent<Object> ()
    .SetGroupName ("Network")
    .AddConstructor<TdmaMac> ();
  return tid;
}

TdmaMac::TdmaMac ()
  : m_nodeId (0),
    m_slotDuration (MilliSeconds (20)),
    m_slotNumber (0)
{
  NS_LOG_FUNCTION (this);
}

TdmaMac::~TdmaMac ()
{
  NS_LOG_FUNCTION (this);
}

void
TdmaMac::SetSlotDuration (Time slotDuration)
{
  m_slotDuration = slotDuration;
}

void
TdmaMac::SetNodeId (uint32_t id)
{
  m_nodeId = id;
}

void
TdmaMac::Enqueue (Ptr<Packet> pkt)
{
  NS_LOG_INFO ("节点 " << m_nodeId << " 在时隙 " << m_slotNumber
               << " 排队一个大小为 " << pkt->GetSize () << " 字节的数据包");
  // 实际实现中，可以将数据包保存到队列中，待到相应时隙发送
}

void
TdmaMac::ScheduleNextSlot ()
{
  m_slotNumber++;
  NS_LOG_INFO ("节点 " << m_nodeId << " 进入时隙 " << m_slotNumber);
  // 这里可以添加发送队列处理、时隙内发送控制等逻辑

  // 调度下一个时隙
  m_slotEvent = Simulator::Schedule (m_slotDuration, &TdmaMac::ScheduleNextSlot, this);
}

void
TdmaMac::Start ()
{
  NS_LOG_INFO ("启动节点 " << m_nodeId << " 的 TDMA MAC 调度");
  // 启动时调度下一个时隙
  m_slotEvent = Simulator::Schedule (m_slotDuration, &TdmaMac::ScheduleNextSlot, this);
}
} // namespace ns3
