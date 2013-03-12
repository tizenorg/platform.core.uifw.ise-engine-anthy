Name:       ise-engine-anthy
Summary:    Japanese input method
Version:    0.0.0125
Release:    1
Group:      System/I18n/Japanese
License:    GPL
URL:        http://sourceforge.jp/projects/scim-imengine/
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  prelink
BuildRequires:  gettext-tools
BuildRequires:  pkgconfig(isf)
BuildRequires:  pkgconfig(anthy)


%description
ISF is an input service framework for TIZEN.
Ise-engine-anthy is ISF IMEngine module for Japanese input method base.It converts Hiragana text to Kana Kanji mixed text.



%prep
%setup -q

%build
%autogen
%configure --prefix=%{_prefix} --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install


%files
%defattr(-,root,root,-)
%{_datadir}/scim/icons/*
%{_datadir}/locale/*
%{_datadir}/scim/Anthy/*
%{_libdir}/scim-1.0/1.4.0/IMEngine/*
