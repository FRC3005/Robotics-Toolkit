﻿<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="19008000">
	<Item Name="Test" Type="Target Folder"/>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Controller" Type="Folder" URL="../Controller">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Geometry" Type="Folder" URL="../Geometry">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Kinematics" Type="Folder" URL="../Kinematics">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Simulation" Type="Folder" URL="../Simulation">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Spline" Type="Folder" URL="../Spline">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Trajectory" Type="Folder" URL="../Trajectory">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Testing.vi" Type="VI" URL="../Testing.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_AALPro.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALPro.lvlib"/>
				<Item Name="NI_Matrix.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/Matrix/NI_Matrix.lvlib"/>
				<Item Name="NI_PtbyPt.lvlib" Type="Library" URL="/&lt;vilib&gt;/ptbypt/NI_PtbyPt.lvlib"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="main.dll" Type="Document" URL="../Spline/Quintic Hermite/main.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
