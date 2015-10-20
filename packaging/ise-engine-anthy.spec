Name:       ise-engine-anthy
Summary:    Anthy (Japanese) Input Method Engine for ISF
Version:    0.0.0125
Release:    3
Group:      Graphics & UI Framework/Input
License:    GPL-2.0+
URL:        http://sourceforge.jp/projects/scim-imengine/
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  prelink
BuildRequires:  gettext-tools
BuildRequires:  pkgconfig(isf)
BuildRequires:  pkgconfig(anthy)
BuildRequires:  pkgconfig(ecore-imf)

%description
ISF is an input service framework for TIZEN.
ise-engine-anthy is ISF IMEngine module for Japanese input method base.It converts Hiragana text to Kana Kanji mixed text.



%prep
%setup -q

%build
./bootstrap
%configure --prefix=%{_prefix} --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}%{_datadir}/license
cp COPYING %{buildroot}%{_datadir}/license/%{name}
%make_install

%post
pkg_initdb

%postun
pkg_initdb

%files
%manifest %{name}.manifest
%defattr(-,root,root,-)
%{_datadir}/license/%{name}
%{_datadir}/scim/icons/*
%{_datadir}/locale/*
%{_datadir}/packages/*
%{_datadir}/scim/Anthy/*
%{_libdir}/scim-1.0/1.4.0/IMEngine/*
