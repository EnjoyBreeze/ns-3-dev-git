/* TdmaNetDevice.h */
#ifndef TDMA_NET_DEVICE_H
#define TDMA_NET_DEVICE_H

#include "ns3/net-device.h"
#include "ns3/ptr.h"
#include "ns3/address.h"

namespace ns3 {

class SpectrumPhy;

class TdmaNetDevice : public NetDevice
{
public:
  static TypeId GetTypeId (void);
  TdmaNetDevice ();
  virtual ~TdmaNetDevice ();

  // NetDevice 基础方法
  virtual void SetIfIndex (const uint32_t index);
  virtual uint32_t GetIfIndex (void) const;
//   virtual Ptr<Channel> GetChannel (void) const;
  virtual void SetAddress (Address address);
  virtual Address GetAddress (void) const;
  virtual bool SetMtu (const uint16_t mtu);
  virtual uint16_t GetMtu (void) const;
  virtual bool IsLinkUp (void) const;
  virtual void AddLinkChangeCallback (Callback<void> callback);
  virtual bool IsBroadcast (void) const;
  virtual Address GetBroadcast (void) const;
  virtual bool IsMulticast (void) const;
  virtual Address GetMulticast (Ipv4Address multicastGroup) const;
  virtual bool IsPointToPoint (void) const;
  virtual bool IsBridge (void) const;
  virtual bool Send (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber);
  virtual bool SendFrom (Ptr<Packet> packet, const Address& source, const Address& dest, uint16_t protocolNumber);
  virtual Ptr<Node> GetNode (void) const;
  virtual void SetNode (Ptr<Node> node);
  virtual bool NeedsArp (void) const;
  virtual void SetReceiveCallback (NetDevice::ReceiveCallback cb);
  virtual void SetPromiscReceiveCallback (PromiscReceiveCallback cb);
  virtual bool SupportsSendFrom (void) const;

  // 自定义接口：设置物理层和 TDMA MAC
  void SetPhy (Ptr<SpectrumPhy> phy);
  void SetTdmaMac (Ptr<Object> tdmaMac); // 指向 TdmaMac 对象

private:
  Ptr<SpectrumPhy> m_phy;
  Ptr<Object> m_tdmaMac; // 实际应为 TdmaMac
  Ptr<Node> m_node;
  uint32_t m_ifIndex;
};

} // namespace ns3

#endif // TDMA_NET_DEVICE_H
