char data[][256] = {"enable",
"conf ter",
"hostname Atom",
"no ip domain-lookup",
"enable secret cisco",
"line console 0",
"password cisco",
"login",
"line vty 0 15",
"password cisco",
"login",
"exit",
"int g0/0.20",
"encapsulation dot1Q 20",
"ip address 172.16.20.254 255.255.255.0",
"int g0/0.40",
"encapsulation dot1Q 40",
"ip address 172.16.40.254 255.255.255.0",
"int g0/0.60",
"encapsulation dot1Q 60",
"ip address 172.16.60.254 255.255.255.0",
"int g0/0.88",
"encapsulation dot1Q 88",
"ip address 172.16.88.254 255.255.255.0",
"int g0/0",
"no sh",
"int g0/1.250",
"encapsulation dot1Q 250",
"ip address 172.16.250.254 255.255.255.0",
"int g0/1.254",
"encapsulation dot1Q 254",
"ip address 172.16.254.254 255.255.255.0",
"int g0/1",
"no shutdown",
"exit",
"access-list 10 permit 172.16.60.0 0.0.0.255",
"access-list 10 deny any",
"ip access-list standard INT-WEB",
"permit 172.16.40.0 0.0.0.255",
"permit 172.16.60.0 0.0.0.255",
"exit",
"line vty 0 15",
"access-class 10 in",
"exit",
"int g0/1.250",
"ip access-group INT-WEB out",
"en",
"conf ter",
"hostname Neutron",
"no ip domain-lookup",
"enable secret cisco",
"line console 0",
"password cisco",
"login",
"line vty 0 15",
"password cisco",
"login",
"exit",
"service password-encryption",
"vlan 20",
"name Clerical",
"vlan 40",
"name Acct",
"vlan 60",
"name HR",
"vlan 88",
"name NetAdmin",
"exit",
"int vlan 88",
"ip add 172.16.88.253 255.255.255.0",
"no shutdown",
"exit",
"ip default-gateway 172.16.88.254",
"vtp domain School",
"int g0/1",
"switchport mode trunk",
"int range f0/23-24",
"switchport mode trunk",
"en",
"conf ter",
"hostname Proton",
"vlan 20",
"name Clerical",
"vlan 40",
"name Acct",
"vlan 60",
"name HR",
"vlan 88",
"name NetAdmin",
"exit",
"int range fastEthernet 0/1-5",
"switchport mode access",
"switchport access vlan 20",
"int range fastEthernet 0/6-10",
"switchport mode access",
"switchport access vlan 40",
"int range fastEthernet 0/11-15",
"switchport mode access",
"switchport access vlan 60",
"exit",
"int vlan 88",
"ip add 172.16.88.252 255.255.255.0",
"no sh",
"no shutdown",
"exit",
"ip default-gateway 172.16.88.254",
"vtp domain School",
"int f0/23",
"switchport mode trunk",
"en",
"conf ter",
"hostname Electron",
"vlan 20",
"name Clerical",
"vlan 40",
"name Acct",
"vlan 60",
"name HR",
"vlan 88",
"name NetAdmin",
"exit",
"int range fa0/1-5",
"switchport mode access",
"switchport access vlan 20",
"int range fa0/6-10",
"switchport mode access",
"switchport access vlan 40",
"int range fa0/11-15",
"switchport mode access",
"switchport access vlan 60",
"exit",
"int vlan 88",
"ip add 172.16.88.251 255.255.255.0",
"no shutdown",
"exit",
"ip default-gateway 172.16.88.254",
"vtp domain School",
"int f0/24",
"switchport mode trunk"};
int MaxSize = 139;