# ccf_app

VCX Aplication using CCF (Cluster Client Failover) for managing 
distrobuted file access in a windows failover cluster

Public docs on this feature which have been referenced are below

[Failover Cluster APIs](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/mscs/failover-cluster-apis-portal)

[Dev Environment For using Cluster Failover APIs](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/mscs/preparing-a-development-environment#ide-requirements)

[SMB Client APis](https://docs.microsoft.com/en-us/windows/win32/api/smbclnt/)

CCF Allows for applications running in a windows failover cluster to gracefully resolve closing of old file handles, and re-opening of files, during 
a process crash.

This is accomplished by registering processes in the cluster via an App Instance ID, which is a GUID that uniquely identifies that Application. This, combined
with a monotonically increasing app instance version let's CCF disseminate which attempts to access a file should be respected (the newest process) and which
should be ignored (tombstoned processes which try to re-open files later on.
