
// sim65View.cpp : implementation of the Csim65View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "sim65.h"
#endif

#include "sim65Doc.h"
#include "sim65View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csim65View

IMPLEMENT_DYNCREATE(Csim65View, CView)

BEGIN_MESSAGE_MAP(Csim65View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Csim65View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Csim65View construction/destruction

Csim65View::Csim65View() noexcept
{
	// TODO: add construction code here

}

Csim65View::~Csim65View()
{
}

BOOL Csim65View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Csim65View drawing

void Csim65View::OnDraw(CDC* /*pDC*/)
{
	Csim65Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Csim65View printing


void Csim65View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Csim65View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Csim65View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Csim65View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Csim65View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Csim65View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Csim65View diagnostics

#ifdef _DEBUG
void Csim65View::AssertValid() const
{
	CView::AssertValid();
}

void Csim65View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csim65Doc* Csim65View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csim65Doc)));
	return (Csim65Doc*)m_pDocument;
}
#endif //_DEBUG


// Csim65View message handlers
